-- =====================================================================================================================
-- ============================================ LAB 7: SQL Views and Roles =============================================
-- =====================================================================================================================

-- ============================================== Part 1: Database Setup ===============================================

CREATE TABLE employees (
    emp_id int primary key,
    emp_name varchar(50),
    dept_id int,
    salary decimal(10, 2)
);

CREATE TABLE departments (
    dept_id int primary key,
    dept_name varchar(50),
    location varchar(50)
);

CREATE TABLE projects (
    project_id int primary key,
    project_name varchar(50),
    dept_id int,
    budget decimal(10, 2)
);

-- =========================================== Part 2: Creating Basic Views ============================================

-- Exercise 2.1: Simple View Creation
CREATE VIEW employee_details AS
SELECT emp_name, salary, dept_name, location
FROM employees
INNER JOIN departments USING (dept_id);

SELECT * FROM employee_details;

-- Exercise 2.2: View with Aggregation
CREATE VIEW dept_statistics AS
SELECT d.dept_name, employee_count, avg_salary, max_salary, min_salary
FROM departments d
LEFT JOIN (
    SELECT
        dept_id,
        count(*) AS employee_count,
        avg(salary) AS avg_salary,
        max(salary) AS max_salary,
        min(salary) AS min_salary
    FROM employees e
    group by dept_id
) e ON d.dept_id = e.dept_id;

SELECT * FROM dept_statistics
ORDER BY employee_count DESC;

-- Exercise 2.3: View with Multiple Joins
CREATE VIEW project_overview AS
SELECT project_name, budget, dept_name, location, employee_count
FROM projects
INNER JOIN departments USING (dept_id)
LEFT JOIN (SELECT dept_id, count(*) as employee_count FROM employees GROUP BY dept_id) z USING (dept_id);

SELECT * FROM project_overview;

-- Exercise 2.4: View with Filtering
CREATE VIEW high_earners AS
SELECT emp_name, salary, dept_name
FROM employees
LEFT JOIN departments USING (dept_id)
WHERE salary > 55000;

SELECT * FROM high_earners;

-- ======================================= Part 3: Modifying and Managing Views ========================================

-- Exercise 3.1: Replace a View
CREATE OR REPLACE VIEW employee_details AS
SELECT emp_name, salary, dept_name, location, CASE
        WHEN salary > 60000 THEN 'High'
        WHEN salary > 50000 THEN 'Medium'
        WHEN salary <= 50000 THEN 'Standard'
    END AS salary_grade
FROM employees
INNER JOIN departments USING (dept_id);

SELECT * FROM employee_details;

-- Exercise 3.2: Rename a View
ALTER VIEW high_earners RENAME TO top_performers;

SELECT * FROM top_performers;

-- Exercise 3.3: Drop a View
CREATE TEMPORARY VIEW temp_view AS
    SELECT * FROM employees WHERE salary < 50000;

SELECT * FROM temp_view;

DROP VIEW temp_view;

-- ============================================== Part 4: Updatable Views ==============================================

-- Exercise 4.1: Create an Updatable View
CREATE VIEW employee_salaries AS
    SELECT emp_id, emp_name, dept_id, salary FROM employees;

-- Exercise 4.2: Update Through a View
UPDATE employee_salaries
SET salary = 52000
WHERE emp_name = 'John Smith';

SELECT * FROM employee_salaries;

-- Exercise 4.3: Insert Through a View
INSERT INTO employee_salaries
VALUES (6, 'Alice Johnson', 102, 58000);

-- Exercise 4.4: View with CHECK OPTION
CREATE VIEW it_employees AS
    SELECT *
    FROM employees
    WHERE dept_id = 101 WITH LOCAL CHECK OPTION;

INSERT INTO it_employees
(emp_id, emp_name, dept_id, salary)
VALUES (7, 'Bob Wilson', 103, 60000);

-- ============================================ Part 5: Materialized Views =============================================

-- Exercise 5.1
CREATE MATERIALIZED VIEW dept_summary_mv AS
    SELECT
        dept_id,
        dept_name,
        coalesce(number_of_employees, 0) AS number_of_employees,
        coalesce(total_salaries, 0) AS total_salaries,
        coalesce(number_of_projects, 0) AS number_of_projects,
        coalesce(total_project_budget, 0) AS total_project_budget
    FROM departments
    LEFT JOIN (
        SELECT
            dept_id,
            count(*) AS number_of_employees,
            sum(salary) AS total_salaries
        FROM employees GROUP BY dept_id
    ) z USING (dept_id)
    LEFT JOIN (
        SELECT
            dept_id,
            count(*) AS number_of_projects,
            sum(budget) AS total_project_budget
        FROM projects
        GROUP BY dept_id
    ) p USING (dept_id)
WITH DATA;

SELECT * FROM dept_summary_mv;

-- Exercise 5.2 Refresh Materialized View
INSERT INTO employees VALUES (8, 'Charlie Brown', 101, 54000);
REFRESH MATERIALIZED VIEW dept_summary_mv;


-- Exercise 5.3: Concurrent Refresh
CREATE UNIQUE INDEX idx_dept_summary_dept_id ON dept_summary_mv(dept_id);
REFRESH MATERIALIZED VIEW CONCURRENTLY dept_summary_mv;

-- Exercise 5.4: Materialized View with NO DATA
CREATE MATERIALIZED VIEW project_stats_mv AS
    SELECT project_name, budget, dept_name, coalesce(c, 0) AS employees_count
    FROM projects
    LEFT JOIN departments USING (dept_id)
    LEFT JOIN (SELECT dept_id, count(*) AS c FROM employees GROUP BY dept_id) z USING (dept_id)
WITH NO DATA;

SELECT * FROM project_stats_mv;

-- ============================================== Part 6: Database Roles ===============================================

-- Exercise 6.1: Create Basic Roles
CREATE ROLE analyst NOLOGIN;
CREATE ROLE data_viewer LOGIN PASSWORD 'viewer123';
CREATE USER report_user PASSWORD 'report456';

SELECT rolname FROM pg_roles WHERE rolname NOT LIKE 'pg_%';

-- Exercise 6.2: Role with Specific Attributes
CREATE ROLE db_creator CREATEDB LOGIN PASSWORD 'creator789';
CREATE ROLE user_manager CREATEROLE LOGIN PASSWORD 'manager101';
CREATE ROLE admin_user SUPERUSER LOGIN PASSWORD 'admin999';

-- Exercise 6.3: Grant Privileges to Roles
GRANT SELECT ON employees, departments, projects TO analyst;
GRANT ALL PRIVILEGES ON employee_details TO data_viewer;
GRANT SELECT, INSERT ON employees TO report_user;

-- Exercise 6.4: Create Group Roles
CREATE ROLE hr_team;
CREATE ROLE finance_team;
CREATE ROLE it_team;

CREATE USER hr_user1 PASSWORD 'hr001';
CREATE USER hr_user2 PASSWORD 'hr002';
CREATE USER finance_user1 PASSWORD 'fin001';

GRANT hr_team TO hr_user1, hr_user2;
GRANT finance_team to finance_user1;

GRANT SELECT, UPDATE ON employees TO hr_team;
GRANT SELECT ON dept_statistics TO finance_team;

-- Exercise 6.5: Revoke Attributes
REVOKE UPDATE ON employees FROM hr_team;
REVOKE hr_team FROM hr_user2;
REVOKE ALL PRIVILEGES ON employee_details FROM data_viewer;

-- Exercise 6.6: Modify Role Attributes
ALTER ROLE analyst PASSWORD 'analyst123';
ALTER ROLE user_manager SUPERUSER;
ALTER ROLE analyst PASSWORD NULL;
ALTER ROLE data_viewer CONNECTION LIMIT 5;

-- ========================================== Part 7: Advanced Role Managment ==========================================

-- Exercise 7.1: Role Hierarchies
CREATE ROLE read_only;
GRANT SELECT ON ALL TABLES IN SCHEMA labs TO read_only;

CREATE ROLE junior_analyst PASSWORD 'junior123';
CREATE ROLE senior_analyst PASSWORD 'senior123';

GRANT read_only TO junior_analyst, senior_analyst;

GRANT INSERT, UPDATE ON employees TO senior_analyst;

-- Exercise 7.2: Object Ownership
CREATE ROLE project_manager LOGIN PASSWORD 'pm123';
ALTER TABLE dept_statistics OWNER TO project_manager;
ALTER TABLE projects OWNER TO project_manager;

SELECT tablename, tableowner
FROM pg_tables
WHERE schemaname = 'labs';

-- Exercise 7.3: Reassign and Drop Roles
CREATE ROLE temp_owner LOGIN;
CREATE TABLE temp_table (
    id int
);
ALTER TABLE temp_table OWNER TO temp_owner;
REASSIGN OWNED BY temp_owner TO postgres;
DROP OWNED BY temp_owner;
DROP ROLE temp_owner;

-- Exercise 7.4: Row-Level Security with Views
CREATE VIEW hr_employee_view AS
    SELECT * FROM employees WHERE dept_id = 102;
GRANT SELECT ON hr_employee_view TO hr_team;

CREATE VIEW finance_employee_view AS
    SELECT emp_id, emp_name, salary FROM employees;
GRANT SELECT ON finance_employee_view TO finance_team;


-- ============================================ Part 8: Practical Scenarios ============================================

-- Exercise 8.1: Department Dashboard View
CREATE OR REPLACE VIEW dept_dashboard AS
    SELECT
        dept_id,
        location,
        employee_count,
        avg_salary,
        number_of_projects,
        total_project_budget,
        (total_project_budget/coalesce(employee_count, 1)) AS budget_per_employee
    FROM departments
    LEFT JOIN dept_statistics USING (dept_name)
    LEFT JOIN dept_summary_mv USING (dept_id);

SELECT * FROM dept_dashboard;


-- Exercise 8.2: Audit View
ALTER TABLE projects ADD COLUMN created_date TIMESTAMP DEFAULT NOW();

CREATE OR REPLACE VIEW high_budget_projects AS
    SELECT
        project_name,
        budget,
        dept_name,
        created_date,
        CASE
            WHEN budget > 150000 THEN 'Critical Review Required'
            WHEN budget > 100000 THEN 'Managment Approval Needed'
            ELSE 'Standard Process'
        END AS approval_status
    FROM projects
    LEFT JOIN departments USING (dept_id)
    WHERE budget > 75000;

SELECT * FROM high_budget_projects;

-- Exercise 8.3: Create Access Control System
CREATE ROLE viewer_role;
GRANT SELECT ON ALL TABLES IN SCHEMA labs TO viewer_role;

CREATE ROLE entry_role;
GRANT viewer_role TO entry_role;
GRANT INSERT ON employees, projects TO entry_role;

CREATE ROLE analyst_role;
GRANT entry_role TO analyst_role;
GRANT UPDATE ON employees, projects TO analyst_role;

CREATE ROLE manager_role;
GRANT analyst_role TO manager_role;
GRANT DELETE ON employees, projects TO manager_role;

CREATE USER alice PASSWORD 'alice123';
CREATE USER bob PASSWORD 'bob123';
CREATE USER charlie PASSWORD 'charlie123';

GRANT viewer_role TO alice;
GRANT analyst_role TO bob;
GRANT manager_role TO charlie;
