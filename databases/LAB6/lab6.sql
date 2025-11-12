-- ============================================== Part 1: Database Setup ===============================================

-- Step 1.1

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

-- Step 1.2: Insert Sample Data

INSERT INTO employees (emp_id, emp_name, dept_id, salary)
VALUES
    (1, 'John Smith', 101, 50000),
    (2, 'Jane Doe', 102, 60000),
    (3, 'Mike Johnson', 101, 55000),
    (4, 'Sarah Williams', 103, 65000),
    (5, 'Tom Brown', NULL, 45000);

INSERT INTO departments (dept_id, dept_name, location)
VALUES
    (101, 'IT', 'Building A'),
    (102, 'HR', 'Building B'),
    (103, 'Finance', 'Building C'),
    (104, 'Marketing', 'Building D');

INSERT INTO projects (project_id, project_name, dept_id, budget)
VALUES
    (1, 'Website Redesign', 101, 100000),
    (2, 'Employee Training', 102, 50000),
    (3, 'Budget Analysis', 103, 75000),
    (4, 'Cloud Migration', 101, 150000),
    (5, 'AI Research', NULL, 200000);

-- =========================================== Part 2: CROSS JOIN Exercises ============================================

-- Exercise 2.1: Basic CROSS JOIN
SELECT e.emp_name, d.dept_name
FROM employees e CROSS JOIN departments d;

-- Exercise 2.2: Alternative CROSS JOIN Syntax
SELECT e.emp_name, d.dept_name
FROM employees e, departments d;

SELECT e.emp_name, d.dept_name
FROM employees e INNER JOIN departments d ON TRUE;

-- Exercise 2.3: Practical CROSS JOIN
SELECT e.emp_name, p.project_name
FROM employees e, projects p;

-- =========================================== Part 3: INNER JOIN Exercises ============================================

-- Exercise 3.1: Basic INNER JOIN with ON
SELECT e.emp_name, d.dept_name, d.location
FROM employees e
INNER JOIN departments d ON d.dept_id = e.dept_id;

-- Exercise 3.2: INNER JOIN with USING
SELECT e.emp_name, d.dept_name, d.location
FROM employees e
INNER JOIN departments d USING (dept_id);

-- Exercise 3.3: NATURAL INNER JOIN
SELECT emp_name, dept_name, location
FROM employees
NATURAL INNER JOIN departments;

-- Exercise 3.4: Multi-table INNER JOIN
SELECT e.emp_name, d.dept_name, p.project_name
FROM employees e
INNER JOIN departments d ON e.dept_id = d.dept_id
INNER JOIN projects p ON d.dept_id = p.dept_id;

-- ============================================ Part 4: LEFT JOIN Exercise =============================================

-- Exercise 4.1: Basic LEFT JOIN
SELECT e.emp_name, d.dept_name
FROM employees e
LEFT JOIN departments d ON e.dept_id = d.dept_id;

-- Exercise 4.2: LEFT JOIN with USING
SELECT e.emp_name, d.dept_name
FROM employees e
LEFT JOIN departments d USING (dept_id);

-- Exercise 4.3: Find Unmatched Records
SELECT e.emp_name, d.dept_name
FROM employees e
LEFT JOIN departments d ON e.dept_id = d.dept_id
WHERE e.dept_id IS NULL;

-- Exercise 4.4: LEFT JOIN with Aggregation
SELECT d.dept_name, count(e.emp_id)
FROM departments d
LEFT JOIN employees e ON e.dept_id = d.dept_id
GROUP BY d.dept_name;

-- =========================================== Part 5: RIGHT JOIN Exercises ============================================

-- Exercise 5.1: Basic RIGHT JOIN
SELECT e.emp_name, d.dept_name
FROM employees e
RIGHT JOIN departments d ON e.dept_id = d.dept_id;

-- Exercise 5.2: Convert to LEFT JOIN
SELECT e.emp_name, d.dept_name
FROM departments d
LEFT JOIN employees e ON e.dept_id = d.dept_id;

-- Exercise 5.3: Find Departments Without Employees
SELECT d.dept_name, d.location
FROM employees e
RIGHT JOIN departments d USING (dept_id)
WHERE e.emp_name IS NULL;

-- ============================================ Part 6: FULL JOIN Exercises ============================================

-- Exercise 6.1: Basic FULL JOIN
SELECT e.emp_name, d.dept_name
FROM employees e
FULL JOIN departments d ON e.dept_id = d.dept_id;

-- Exercise 6.2: FULL JOIN with Projects
SELECT d.dept_name, p.project_name, p.budget
FROM departments d
FULL JOIN projects p ON d.dept_id = p.dept_id;

-- Exercise 6.3: Find Orphanded Records
SELECT e.emp_name, d.dept_name,
       CASE
           WHEN e.emp_name IS NULL THEN 'Department without employees'
           WHEN d.dept_name IS NULL THEN 'Employee without department'
       END AS status
FROM employees e
FULL JOIN departments d ON e.dept_id = d.dept_id
WHERE e.emp_name IS NULL OR d.dept_name IS NULL;

-- ============================================ Part 7: ON vs WHERE Clause =============================================

-- Exercise 7.1: Filtering in ON Clause (Outer Join)
SELECT e.emp_name, d.dept_name, e.salary
FROM employees e
LEFT JOIN departments d ON e.dept_id = d.dept_id AND d.location = 'Building A';

-- Exercise 7.2: Filtering in WHERE Clause (Outer Join)
SELECT e.emp_name, d.dept_name, e.salary
FROM employees e
LEFT JOIN departments d ON e.dept_id = d.dept_id
WHERE d.location = 'Building A';

-- Exercise 7.3: ON vs WHERE with INNER JOIN
SELECT e.emp_name, d.dept_name, e.salary
FROM employees e
INNER JOIN departments d ON e.dept_id = d.dept_id AND d.location = 'Building A';

SELECT e.emp_name, d.dept_name, e.salary
FROM employees e
INNER JOIN departments d ON e.dept_id = d.dept_id
WHERE d.location = 'Building A';

-- ========================================== Part 8: Complex JOIN Scenarios ===========================================

-- Exercise 8.1: Multiple Joins with Different Types
SELECT
    d.dept_name,
    e.emp_name,
    e.salary,
    p.project_name,
    p.budget
FROM departments d
LEFT JOIN employees e USING (dept_id)
LEFT JOIN projects p USING (dept_id)
ORDER BY d.dept_name, e.emp_name;

-- Exercise 8.2: Self Join
ALTER TABLE employees ADD COLUMN manager_id int;

UPDATE employees SET manager_id = 3 WHERE emp_id in (1, 2, 4, 5);
UPDATE employees SET manager_id = NULL WHERE emp_id = 3;

SELECT
    e.emp_name AS employee,
    m.emp_name AS manager
FROM employees e
LEFT JOIN employees m ON e.manager_id = m.emp_id;

-- Exercise 8.3: Join with Subquery
SELECT d.dept_name, AVG(e.salary) AS avg_salary
FROM departments d
INNER JOIN employees e USING (dept_id)
GROUP BY d.dept_name
HAVING AVG(e.salary) > 50000;


-- ================================================== In-Class Tasks ===================================================

-- q1

SELECT e.emp_name,
       CASE
           WHEN d.location IS NULL THEN 'Not Assigned'
           WHEN d.location IS NOT NULL THEN d.location
       END as building
FROM employees e
LEFT JOIN departments d USING (dept_id)
ORDER BY e.emp_name;

-- q2

select d.dept_name, e.cnt_e AS employee_count, p.p_cnt as project_count, z.r_cnt as resources_count
FROM departments d
LEFT JOIN (SELECT dept_id, count(emp_name) as cnt_e FROM employees GROUP BY  dept_id) e USING (dept_id)
LEFT JOIN (SELECT dept_id, count(project_name) as p_cnt FROM projects GROUP BY  dept_id) p USING (dept_id)
LEFT JOIN (SELECT em.dept_id, count(emp_name) as r_cnt FROM employees em, projects pj WHERE em.dept_id = pj.dept_id GROUP BY em.dept_id) z USING (dept_id);

-- q3

SELECT d.dept_name, sum(p.budget)
FROM departments d
LEFT JOIN projects p USING (dept_id)
WHERE p.project_name IS NOT NULL
GROUP BY d.dept_name;

-- q4

SELECT e.emp_name, d.dept_name, e.salary, a.avg_salary, (e.salary-a.avg_salary) as comarison
FROM employees e
LEFT JOIN departments d USING (dept_id)
LEFT JOIN (SELECT dept_id, avg(salary) as avg_salary FROM employees GROUP BY dept_id) AS a USING (dept_id);

-- q5

SELECT 'Employee' as resource_type, e.emp_name as resource_name, e.salary as value, 'No Department Assigned' as status
FROM employees e
LEFT JOIN departments d USING (dept_id)
WHERE d.dept_id IS NULL
UNION (
    SELECT 'Project' as resource_type, p.project_name as resource_name, p.budget as value, 'No Department Assigned' as status
    FROM projects p
    LEFT JOIN departments d USING (dept_id)
    WHERE d.dept_id IS NULL
);