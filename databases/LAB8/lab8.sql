-- =====================================================================================================================
-- ================================================ Lab 8: SQL Indexes =================================================
-- =====================================================================================================================

-- ============================================== Part 1: Database Setup ===============================================

CREATE TABLE departments (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(50),
    location VARCHAR(50)
);

CREATE TABLE employees (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(100),
    dept_id INT,
    salary DECIMAL(10,2),
    FOREIGN KEY (dept_id) REFERENCES departments(dept_id)
);

CREATE TABLE projects (
    proj_id INT PRIMARY KEY,
    project_name VARCHAR(100),
    budget DECIMAL(12,2),
    dept_id INT,
    FOREIGN KEY (dept_id) REFERENCES departments(dept_id)
);


INSERT INTO departments VALUES
    (101, 'IT', 'Building A'),
    (102, 'HR', 'Building B'),
    (103, 'Operations', 'Building C');

INSERT INTO employees VALUES
    (1, 'John Smith', 101, 50000),
    (2, 'Jane Doe', 101, 55000),
    (3, 'Mike Johnson', 102, 48000),
    (4, 'Sarah Williams', 102, 52000),
    (5, 'Tom Brown', 103, 60000);

INSERT INTO projects VALUES
    (201, 'Website Redesign', 75000, 101),
    (202, 'Database Migration', 120000, 101),
    (203, 'HR System Upgrade', 50000, 102);


-- ========================================== Part 2: Creating Basic Indexes ===========================================

-- Exercise 2.1: Create a Simple B-tree Index
CREATE INDEX emp_salary_idx ON employees(salary);

SELECT indexname, indexdef FROM pg_indexes where tablename = 'employees';

-- Exercise 2.2: Create an Index on a Foreign Key
CREATE INDEX emp_dept_idx ON employees(dept_id);

-- Exercise 2.3: View Index Information
SELECT
    tablename,
    indexname,
    indexdef
FROM pg_indexes
WHERE schemaname = 'labs'
ORDER BY tablename, indexname;


-- ============================================ Part 3: Multicolumn Indexes ============================================

-- Exercise 3.1: Create a Multicolumn Index
CREATE INDEX emp_dept_salary_idx ON employees(dept_id, salary);

SELECT emp_name, salary
FROM employees
WHERE dept_id = 101 AND salary > 52000;

-- Exercise 3.2: Understanding Column Order
CREATE INDEX emp_salary_dept_idx ON employees(salary, dept_id);


-- ============================================== Part 4: Unique Indexes ===============================================

-- Exercise 4.1: Create a Unique Index
ALTER TABLE employees ADD COLUMN email VARCHAR(100);

UPDATE employees SET email = 'john.smith@company.com' WHERE emp_id = 1;
UPDATE employees SET email = 'jane.doe@company.com' WHERE emp_id = 2;
UPDATE employees SET email = 'mike.johnson@company.com' WHERE emp_id = 3;
UPDATE employees SET email = 'sarah.williams@company.com' WHERE emp_id = 4;
UPDATE employees SET email = 'tom.brown@company.com' WHERE emp_id = 5;

CREATE UNIQUE INDEX emp_email_unique_idx ON employees(email);

INSERT INTO employees (emp_id, emp_name, dept_id, salary, email)
VALUES (6, 'New Employee', 101, 55000, 'john.smith@company.com');


-- Exercise 4.2: Unique Index vs UNIQUE Constraint
ALTER TABLE employees ADD COLUMN phone VARCHAR(20) UNIQUE;

SELECT indexname, indexdef
FROM pg_indexes
WHERE tablename = 'employees' AND indexname LIKE '%phone%';


-- ============================================ Part 5: Indexes and Sorting ============================================

-- Exercise 5.1: Create an Index for Sorting
CREATE INDEX emp_salary_desc_idx ON employees(salary DESC);

-- Exercise 5.2: Index with NULL Handling
CREATE INDEX proj_budget_null_first_idx ON projects(budget NULLS FIRST);


-- ========================================== Part 6: Indexes on Expressions ===========================================

-- Exercise 6.1: Create a Function-Based Index
CREATE INDEX emp_name_lower_idx ON employees(LOWER(emp_name));

SELECT * FROM employees WHERE LOWER(emp_name) = 'john smith';

-- Exercise 6.2: Index on Calculated Values
ALTER TABLE employees ADD COLUMN hire_date DATE;

UPDATE employees SET hire_date = '2020-01-15' WHERE emp_id = 1;
UPDATE employees SET hire_date = '2019-06-20' WHERE emp_id = 2;
UPDATE employees SET hire_date = '2021-03-10' WHERE emp_id = 3;
UPDATE employees SET hire_date = '2020-11-05' WHERE emp_id = 4;
UPDATE employees SET hire_date = '2018-08-25' WHERE emp_id = 5;

CREATE INDEX emp_hire_year_idx ON employees(EXTRACT(YEAR FROM hire_date));

SELECT emp_name, hire_date
FROM employees
WHERE EXTRACT(YEAR FROM hire_date) = 2020;


-- ============================================= Part 7: Managing Indexes ==============================================

-- Exercise 7.1: Rename an Index
ALTER INDEX emp_salary_idx RENAME TO employees_salary_index;

SELECT indexname FROM pg_indexes WHERE tablename = 'employees';

-- Exercise 7.2: Drop Unused Indexes
DROP INDEX emp_salary_dept_idx;

-- Exercise 7.3: Reindex
REINDEX INDEX employees_salary_index;


-- ============================================ Part 8: Practical Scenarios ============================================

-- Exercise 8.1: Optimize a Slow Query
SELECT e.emp_name, e.salary, d.dept_name
FROM employees e
JOIN departments d ON e.dept_id = d.dept_id
WHERE e.salary > 50000
ORDER BY e.salary DESC;

CREATE INDEX emp_salary_filter_idx ON employees(salary) WHERE salary > 50000;

-- Exercise 8.2: Partial Index
CREATE INDEX proj_high_budget_idx ON projects(budget) WHERE budget > 80000;

SELECT project_name, budget
FROM projects
WHERE budget > 80000;

-- Exercise 8.3: Analyze Index Usage
EXPLAIN SELECT * FROM employees WHERE salary > 52000;


-- ========================================== Part 9: Index Types Comparison ===========================================

-- Exercise 9.1: Create a Hash Index
CREATE INDEX dept_name_hash_idx ON departments USING HASH (dept_name);

-- Exercise 9.2: Compare Index Types
CREATE INDEX proj_name_btree_idx ON projects(project_name);
CREATE INDEX proj_name_hash_idx ON projects USING HASH (project_name);


-- ======================================== Part 10: Cleanup and Best Practices ========================================

-- Exercise 10.1: Review All Indexes
SELECT
    schemaname,
    tablename,
    indexname,
    pg_size_pretty(pg_relation_size(indexname::regclass)) as index_size
FROM pg_indexes
WHERE schemaname = 'labs'
ORDER BY tablename, indexname;

-- Exercise 10.2: Drop Unnecessary Indexes
DROP INDEX IF EXISTS proj_name_hash_idx;

-- Exercise 10.3: Document Your Indexes
CREATE VIEW index_documentation AS
SELECT
    tablename,
    indexname,
    indexdef,
    'Improves salary-based queries' as purpose
FROM pg_indexes
WHERE schemaname = 'labs'
AND indexname LIKE '%salary%';

SELECT * FROM index_documentation;

-- =====================================================================================================================
-- =================================================== In-Class Task ===================================================
-- =====================================================================================================================

-- ================================================== Database Setup ===================================================
CREATE TABLE customers (
    customer_id INT PRIMARY KEY,
    rst_name VARCHAR(50),
    last_name VARCHAR(50),
    phone VARCHAR(20),
    account_number VARCHAR(20),
    branch_code VARCHAR(10)
);
CREATE TABLE accounts (
    account_id INT PRIMARY KEY,
    customer_id INT,
    account_type VARCHAR(20),
    balance DECIMAL(15,2),
    status VARCHAR(20),
    opened_date DATE,
    FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);
CREATE TABLE transactions (
    transaction_id INT PRIMARY KEY,
    account_id INT,
    transaction_type VARCHAR(20),
    amount DECIMAL(15,2),
    transaction_date TIMESTAMP,
    description VARCHAR(200),
    FOREIGN KEY (account_id) REFERENCES accounts(account_id)
);

-- ====================================== Task 1: Unique Constraint for Security =======================================

CREATE UNIQUE INDEX account_number_idx ON customers(account_number);

-- Q: What happens if someone tries to insert a duplicate account number?
-- A: It will raise an error

-- ====================================== Task 2: Transaction History Performance ======================================

SELECT transaction_type, amount, transaction_date, description
FROM transactions
WHERE account_id = 45678
  AND transaction_date >= CURRENT_DATE - INTERVAL '90 days'
ORDER BY transaction_date DESC;

CREATE INDEX transactions_idx ON transactions(account_id, transaction_date desc);

-- Q: List the columns in your index in order
-- A: account_id, transaction_date

-- =========================================== Task 3: Active Accounts Only ============================================

CREATE INDEX is_active_idx ON accounts(status);

-- Q_A: Is this a partial index?
-- A_A: No

-- Q_B: Why would a partial index NOT be beneficial in this case:
-- A_B: Because ~95% is Active, so it will spend calculation power for useless operation

-- ======================================= Task 4: Customer Lookup Optimization ========================================

CREATE INDEX last_name_idx ON customers(lower(last_name));

-- Q: What type of index is this?
-- A: Expression index

