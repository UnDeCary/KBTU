
-- Part A: Database and Table Setup
CREATE DATABASE advanced_lab;

CREATE TABLE employees (
    emp_id serial primary key,
    first_name varchar(50),
    last_name varchar(50),
    department varchar(50),
    salary int,
    hire_date date,
    status varchar(20) default 'Active'
);

CREATE TABLE departments (
    dept_id serial primary key,
    dept_name varchar(100),
    budget int,
    manager_id int
);

CREATE TABLE projects (
    project_id serial primary key,
    project_name varchar(100),
    dept_id int,
    start_date date,
    end_date date,
    budget int
);

-- Part B: Advanced INSERT Operations

INSERT INTO employees (emp_id, first_name, last_name, department)
VALUES (1, 'Ryan', 'Gosling', 'SITE');

INSERT INTO employees (emp_id, first_name, last_name, department, hire_date)
VALUES (2, ' Leonardo', 'DiCaprio', 'ISE', '2025-09-01');

INSERT INTO departments (dept_name, budget, manager_id)
VALUES ('SITE', 150_000_000, 1),
       ('ISE', 200_000_000, 2),
       ('SCE', 175_000_000, 2);


SELECT setval('employees_emp_id_seq', (SELECT MAX(emp_id) FROM employees));
INSERT INTO employees (first_name, last_name, department, salary, hire_date)
VALUES ('Walter', 'White', 'SCE', 50_000 * 1.1, NOW());

CREATE TABLE temp_employees (
    emp_id serial primary key,
    first_name varchar(50),
    last_name varchar(50),
    department varchar(50),
    salary int,
    hire_date date,
    status varchar(20) default 'Active'
);

INSERT INTO temp_employees (SELECT * FROM employees WHERE department = 'SITE');

-- Part C: Complex UPDATE Operations

UPDATE employees SET salary = salary*1.1;

UPDATE employees SET status = 'Senior' where salary > 60_000 and hire_date < '2020-01-01';

UPDATE employees
SET department = CASE
    WHEN salary BETWEEN 50_000 and 80_000 THEN 'Senior'
    WHEN salary > 80_000 THEN 'Management'
    ELSE 'Junior'
END;

UPDATE employees SET department = default WHERE status = 'Inactive';

UPDATE departments
SET budget = (SELECT AVG(salary)*1.2 FROM employees where department = dept_name);

UPDATE employees
SET salary = salary * 1.15, status = 'Promoted'
WHERE department = 'Sales';

-- Part D: Advanced DELETE Operations

DELETE FROM employees WHERE status = 'Terminated';

DELETE FROM departments WHERE dept_name NOT IN (SELECT DISTINCT department FROM employees WHERE department IS NOT NULL);

DELETE FROM projects WHERE end_date < '2023-01-01' RETURNING *;

-- Part E: Operations with NULL Values

INSERT INTO employees (first_name, last_name, hire_date, status)
VALUES ('Peter', 'Parker', '2019-04-23', 'Spider');

UPDATE employees
SET department = 'Unassigned'
WHERE department IS NULL;

-- Part F: RETURNING Clause Operations

INSERT INTO employees (first_name, last_name, department, salary, hire_date)
VALUES ('Forrest', 'Gump', 'KMA', 100_000, '2020-03-23')
RETURNING concat(emp_id::varchar, first_name, last_name) as id_full_name;

UPDATE employees
SET salary = salary + 5000
WHERE department = 'SITE'
RETURNING emp_id, salary-5000 as old_salary, salary as new_salary;

DELETE FROM employees
WHERE hire_date < '2020-01-01'
RETURNING *;

-- Part G: Advanced DML Patterns

INSERT INTO employees (first_name, last_name, department, salary, hire_date)
SELECT 'Alan', 'Tyuring', 'SAM', 90_000, '2021-07-12'
WHERE NOT EXISTS (
    SELECT 1
    FROM employees
    WHERE first_name = 'Alan' and last_name = 'Tyuring'
);

UPDATE employees
SET salary = CASE
    WHEN (SELECT budget FROM departments where dept_name = department) > 100_000 THEN salary * 1.1
    ELSE salary * 1.05
END;

INSERT INTO employees (first_name, last_name, department, salary, hire_date)
VALUES ('Mark', 'Zuckerberg', 'SITE', 70_000, '2025-10-01'),
       ('Franklin', 'Roosevelt', 'ISE', 90_000, '2025-10-01'),
       ('Elon', 'Musk', 'SITE', 95_000, '2025-10-01'),
       ('Tony', 'Stark', 'ISE', 105_000, '2025-10-01'),
       ('John', 'Nash', 'SAM', 85_000, '2025-10-01');

UPDATE employees
SET salary = salary * 1.10
WHERE hire_date = '2025-10-01';

CREATE TABLE employee_archive (
      emp_id serial primary key,
      first_name varchar(50),
      last_name varchar(50),
      department varchar(50),
      salary int,
      hire_date date,
      status varchar(20)
);

INSERT INTO employee_archive
SELECT * FROM employees where status = 'Inactive';
DELETE FROM employees WHERE status = 'Inactive';

UPDATE projects
SET end_date = end_date
WHERE budget > 50_000 and
      (SELECT count(*) from employees where department = (SELECT dept_name from departments where dept_id = projects.dept_id)) > 3;
