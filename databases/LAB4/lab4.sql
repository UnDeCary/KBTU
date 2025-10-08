-- ========================== PREPARATION ==========================

-- CREATING TABLES
CREATE TABLE employees (
    employee_id SERIAL PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    department VARCHAR(50),
    salary NUMERIC(10,2),
    hire_date DATE,
    manager_id INTEGER,
    email VARCHAR(100)
);
CREATE TABLE projects (
    project_id SERIAL PRIMARY KEY,
    project_name VARCHAR(100),
    budget NUMERIC(12,2),
    start_date DATE,
    end_date DATE,
    status VARCHAR(20)
);
CREATE TABLE assignments (
    assignment_id SERIAL PRIMARY KEY,
    employee_id INTEGER REFERENCES employees(employee_id),
    project_id INTEGER REFERENCES projects(project_id),
    hours_worked NUMERIC(5,1),
    assignment_date DATE
);

-- INSERTING VALUES
INSERT INTO employees (first_name, last_name, department, salary, hire_date, manager_id, email) VALUES
    ('John', 'Smith', 'IT', 75000, '2020-01-15', NULL, 'john.smith@company.com'),
    ('Sarah', 'Johnson', 'IT', 65000, '2020-03-20', 1, 'sarah.j@company.com'),
    ('Michael', 'Brown', 'Sales', 55000, '2019-06-10', NULL, 'mbrown@company.com'),
    ('Emily', 'Davis', 'HR', 60000, '2021-02-01', NULL, 'emily.davis@company.com'),
    ('Robert', 'Wilson', 'IT', 70000, '2020-08-15', 1, NULL),
    ('Lisa', 'Anderson', 'Sales', 58000, '2021-05-20', 3, 'lisa.a@company.com');

INSERT INTO projects (project_name, budget, start_date, end_date, status) VALUES
    ('Website Redesign', 150000, '2024-01-01', '2024-06-30', 'Active'),
    ('CRM Implementation', 200000, '2024-02-15', '2024-12-31', 'Active'),
    ('Marketing Campaign', 80000, '2024-03-01', '2024-05-31', 'Completed'),
    ('Database Migration', 120000, '2024-01-10', NULL, 'Active');

INSERT INTO assignments (employee_id, project_id, hours_worked, assignment_date) VALUES
    (1, 1, 120.5, '2024-01-15'),
    (2, 1, 95.0, '2024-01-20'),
    (1, 4, 80.0, '2024-02-01'),
    (3, 3, 60.0, '2024-03-05'),
    (5, 2, 110.0, '2024-02-20'),
    (6, 3, 75.5, '2024-03-10');


-- ========================== Part 1: Basic SELECT Queries ==========================

-- Task 1.1
SELECT concat(first_name, ' ', last_name) as full_name, department, salary FROM employees;

-- Task 1.2
SELECT DISTINCT department FROM employees;

-- Task 1.3
SELECT
    project_name,
    budget,
    (
    CASE WHEN budget > 150000 THEN 'Large'
       WHEN budget BETWEEN 100000 AND 150000 THEN 'Medium'
       ELSE 'Small'
    END
    ) as budget_category
FROM projects;

-- Task 1.4
SELECT first_name, coalesce(email, 'No email provided') as email from employees;


-- ========================== Part 2: WHERE Clause and Comparison Operators ==========================

-- Task 2.1
SELECT * FROM employees WHERE hire_date >= '2020-01-01';

-- Task 2.2
SELECT * FROM employees WHERE salary BETWEEN 60000 AND 70000;

-- Task 2.3
SELECT * FROM employees WHERE last_name LIKE 'S%' OR last_name LIKE 'J%';

-- Task 2.4
SELECT * FROM employees WHERE manager_id is not null and department = 'IT';


-- ========================== Part 3: String and Mathematical Functions ==========================

-- Task 3.1
SELECT
    concat(UPPER(first_name), ' ', upper(last_name)) as full_name,
    length(last_name) as length_of_last_name,
    substr(email, 1, 3) as first_3_of_email
FROM employees;

-- Task 3.2
SELECT
    salary * 12 as annual_salary,
    salary as mounthy_salary,
    salary * 0.1 as raise_amount
FROM employees;

-- Task 3.3
SELECT
    FORMAT('Project: %s - Budget: %s - Status: %s', project_name, budget, status)
FROM projects;

-- Task 3.4
SELECT
    concat(first_name, ' ', last_name) as full_name,
    EXTRACT(YEAR FROM AGE(NOW(), hire_date)) as years_with_company
FROM employees;


-- ========================== Part 4: Aggregate Functions and GROUP BY ==========================

-- Task 4.1
SELECT department, AVG(salary) as average_salary FROM employees GROUP BY department;

-- Task 4.2
SELECT project_name, (EXTRACT(EPOCH FROM AGE(end_date, start_date)) / 3600) as hours_spend FROM projects;

-- Task 4.3
SELECT department, count(*) as number_of_employees FROM employees GROUP BY department HAVING count(*) > 1;

-- Task 4.4
SELECT max(salary) as max_salary, min(salary) as min_salary, sum(salary) as total_payroll FROM employees;


-- ========================== Part 5: Set Operations ==========================

-- Task 5.1
SELECT
    employee_id,
    concat(first_name, ' ', last_name) as full_name,
    salary
FROM employees
WHERE salary > 65000
UNION
    (
    SELECT
        employee_id,
        concat(first_name, ' ', last_name) as full_name,
        salary
    FROM employees
    WHERE hire_date > '2020-01-01'
);

-- Task 5.2
SELECT *
FROM employees
WHERE department = 'IT'
INTERSECT (SELECT * FROM employees WHERE salary > 65000);

-- Task 5.3
SELECT *
FROM employees
WHERE employee_id in (
                    SELECT employee_id
                    FROM employees
                    EXCEPT (SELECT employee_id FROM assignments)
                    );


-- ========================== Part 6: Subqueries ==========================

-- Task 6.1
SELECT *
FROM employees
WHERE EXISTS (
    SELECT employee_id
    FROM assignments
    WHERE employees.employee_id = assignments.employee_id
);

-- Task 6.2
SELECT *
FROM employees
WHERE employee_id IN (
    SELECT employee_id
    FROM assignments
    WHERE project_id IN (
            SELECT project_id
            FROM projects
            WHERE status = 'Active'
        )
);

-- Task 6.3
SELECT *
FROM employees
WHERE salary > ANY (SELECT salary FROM employees WHERE department = 'Sales');


-- ========================== Part 7: Complex Queries ==========================

-- Task 7.1
SELECT
    concat(first_name, ' ', last_name) as full_name,
    department,
    (SELECT avg(hours_worked) FROM assignments WHERE employee_id = employees.employee_id) as avg_hours_worked,
    RANK() OVER (PARTITION BY department ORDER BY salary DESC) as salary_rank
FROM employees
ORDER BY department, salary_rank asc;

-- Task 7.2
SELECT
    project_name,
    (SELECT sum(hours_worked) from assignments where project_id = projects.project_id) as total_hours,
    (SELECT count(*) FROM assignments WHERE project_id = projects.project_id) as employees_assigned
FROM projects;

-- Task 7.3
SELECT
    e.department,
    count(e.*) as number_of_employees,
    avg(e.salary) as avg_salary,
    (
    SELECT
        concat(first_name, ' ', last_name)
    FROM employees
    WHERE department = e.department
    ORDER BY salary desc
    limit 1
    ) as highest_paid_employee
FROM employees e
GROUP BY department;