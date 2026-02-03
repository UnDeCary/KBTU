-- =====================================================================================================================
-- ===================================== Lab 10: Transactions and Isolation Levels =====================================
-- =====================================================================================================================

-- ===================================================== 3.1 Setup =====================================================

CREATE TABLE accounts (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    balance DECIMAL(10, 2) DEFAULT 0.00
);
CREATE TABLE products (
    id SERIAL PRIMARY KEY,
    shop VARCHAR(100) NOT NULL,
    product VARCHAR(100) NOT NULL,
    price DECIMAL(10, 2) NOT NULL
);


INSERT INTO accounts (name, balance) VALUES
    ('Alice', 1000.00),
    ('Bob', 500.00),
    ('Wally', 750.00);

INSERT INTO products (shop, product, price) VALUES
    ('Joe''s Shop', 'Coke', 2.50),
    ('Joe''s Shop', 'Pepsi', 3.00);

-- ===================================== 3.2 Task 1: Basic Transaction with COMMIT =====================================

BEGIN;
UPDATE accounts SET balance = balance - 100.00
WHERE name = 'Alice';
UPDATE accounts SET balance = balance + 100.00
WHERE name = 'Bob';
COMMIT;

SELECT  * FROM accounts;

-- ============================================ 3.3 Task 2: Using ROLLBACK =============================================

BEGIN;
UPDATE accounts SET balance = balance - 500.00
WHERE name = 'Alice';

SELECT * FROM accounts WHERE name = 'Alice';

ROLLBACK;

SELECT * FROM accounts WHERE name = 'Alice';


-- ======================================== 3.4 Task 3: Working with SAVEPOINTs ========================================

BEGIN;
UPDATE accounts SET balance = balance - 100.00
WHERE name = 'Alice';

SAVEPOINT my_savepoint;

UPDATE accounts SET balance = balance + 100.00
WHERE name = 'Bob';

ROLLBACK TO my_savepoint;

UPDATE accounts SET balance = balance + 100.00
WHERE name = 'Wally';

COMMIT;

SELECT * FROM accounts;

-- ===================================== 3.5 Task 4: Isolation Level Demontration ======================================

-- T1

BEGIN TRANSACTION ISOLATION LEVEL READ COMMITTED;
SELECT * FROM products WHERE shop = 'Joe''s Shop';
COMMIT;

-- T2

BEGIN;
DELETE FROM products WHERE shop = 'Joe''s Shop';
INSERT INTO products (shop, product, price)
VALUES ('Joe''s Shop', 'Fanta', 3.50);
COMMIT;


-- T1

BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE;
SELECT * FROM products WHERE shop = 'Joe''s Shop';
COMMIT;

-- T2

BEGIN;
DELETE FROM products WHERE shop = 'Joe''s Shop';
INSERT INTO products (shop, product, price)
VALUES ('Joe''s Shop', 'Fanta', 3.50);
COMMIT;

-- ==================================================== 3.6 Task 5 =====================================================

-- T1

BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;
SELECT MAX(price), MIN(price) FROM products
WHERE shop = 'Joe''s Shop';
-- Wait for Terminal 2
SELECT MAX(price), MIN(price) FROM products
WHERE shop = 'Joe''s Shop';
COMMIT;

-- T2

BEGIN;
INSERT INTO products (shop, product, price)
VALUES ('Joe''s Shop', 'Sprite', 4.00);
COMMIT;

-- ==================================================== 3.7 Task 6 =====================================================

-- T1

BEGIN TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
SELECT * FROM products WHERE shop = 'Joe''s Shop';
-- Wait for Terminal 2 to UPDATE but NOT commit
SELECT * FROM products WHERE shop = 'Joe''s Shop';
-- Wait for Terminal 2 to ROLLBACK
SELECT * FROM products WHERE shop = 'Joe''s Shop';
COMMIT;

-- T2

BEGIN;
UPDATE products SET price = 99.99
WHERE product = 'Fanta';
-- Wait here (don't commit yet)
-- Then:
ROLLBACK;


-- ============================================= 4. Independent Exercises ==============================================

-- Ex 1

BEGIN;

-- Check if Bob has enough funds
DO $$
    DECLARE
        bob_balance DECIMAL(10,2);
    BEGIN
        SELECT balance INTO bob_balance FROM accounts WHERE name = 'Bob';

        IF bob_balance < 200 THEN
            RAISE EXCEPTION 'Bob does not have sufficient funds';
        END IF;

        UPDATE accounts
        SET balance = balance - 200
        WHERE name = 'Bob';

        UPDATE accounts
        SET balance = balance + 200
        WHERE name = 'Wally';
    END$$;

COMMIT;


-- Ex 2

BEGIN;

-- Insert new product
INSERT INTO products (shop, product, price)
VALUES ('Test Shop', 'Sprite', 2.00);

SAVEPOINT product_inserted;

-- Update price
UPDATE products
SET price = 3.00
WHERE product = 'Sprite';

SAVEPOINT price_updated;

-- Delete product
DELETE FROM products
WHERE product = 'Sprite';

-- Roll back deletion and rollback price update
ROLLBACK TO product_inserted;

COMMIT;

-- Ex 3

INSERT INTO accounts (name, balance)
VALUES ('Shared', 1000.00);

-- WITH PROBLEM

-- T1
BEGIN TRANSACTION ISOLATION LEVEL READ COMMITTED;

SELECT balance FROM accounts WHERE name = 'Shared';
-- A sees 1000

UPDATE accounts
SET balance = balance - 600
WHERE name = 'Shared';

-- A temporarily: 400
-- DO NOT COMMIT YET
COMMIT;

-- T2
BEGIN TRANSACTION ISOLATION LEVEL READ COMMITTED;

SELECT balance FROM accounts WHERE name = 'Shared';
-- B also sees 1000 (not 400!) ← dirty non-repeatable read

UPDATE accounts
SET balance = balance - 600
WHERE name = 'Shared';

COMMIT;


-- WITHOUT DOUBLE WITHDRAWAL

-- T1
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;

SELECT balance FROM accounts WHERE name = 'Shared';
-- sees 1000

UPDATE accounts
SET balance = balance - 600
WHERE name = 'Shared';

-- now temporary: 400
-- hold transaction
COMMIT;

-- T2
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;

SELECT balance FROM accounts WHERE name = 'Shared';
-- B sees 1000 (snapshot), not 400

UPDATE accounts
SET balance = balance - 600
WHERE name = 'Shared';
-- This will WAIT until Session A commits


-- SERIALIZABLE

-- T1
BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE;

SELECT balance FROM accounts WHERE name = 'Shared';

UPDATE accounts
SET balance = balance - 600
WHERE name = 'Shared';

-- T2
BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE;

SELECT balance FROM accounts WHERE name = 'Shared';

UPDATE accounts
SET balance = balance - 600
WHERE name = 'Shared';



-- Ex 4

BEGIN;

SELECT MAX(price) FROM products;
SELECT MIN(price) FROM products;

COMMIT;

-- =====================================================================================================================
-- =================================================== In-Class Task ===================================================
-- =====================================================================================================================

-- Database setup

CREATE TABLE inventory (
  id serial primary key ,
  product varchar(20),
  quantity int,
  warehouse varchar(20)
);

CREATE TABLE bank_accounts(
    id serial primary key,
    owner varchar(20),
    balance float
);

INSERT INTO inventory VALUES
      ('Laptop', 50, 'Main'),
      ('Mouse', 200, 'Main'),
      ('Keyboard', 150, 'Main');

INSERT INTO bank_accounts VALUES
    ('Alex', 2000.00),
    ('Diana', 3500.00),
    ('Michael', 1500.00);


-- ====================================================== Task 1 =======================================================

BEGIN; -- A 2000 D 3500 M 1500
-- STEP 1
UPDATE bank_accounts SET balance = balance - 600.00
WHERE owner = 'Alex'; -- A 1400 D 3500 M 1500
-- STEP 2
SAVEPOINT transfer_started; --
-- STEP 3
UPDATE bank_accounts SET balance = balance + 600.00
WHERE owner = 'Diana'; -- A 1400 D 4100 M 1500
-- STEP 4
SAVEPOINT transfer_completed; --
-- STEP 5
UPDATE bank_accounts SET balance = balance - 100.00
WHERE owner = 'Diana'; -- A 1400 D 4000 M 1500
-- STEP 6
ROLLBACK TO transfer_started; -- A 1400 D 3500 M 1500
-- STEP 7
UPDATE bank_accounts SET balance = balance + 600.00
WHERE owner = 'Michael'; -- A 1400 D 3500 M 2100
-- STEP 8
COMMIT;
-- STEP 9

-- | Step             | Alex    | Diana   | Michael |
-- | ---------------- | ------- | ------- | ------- |
-- | **Initial**      | 2000.00 | 3500.00 | 1500.00 |
-- | **After Step 2** | 1400.00 | 3500.00 | 1500.00 |
-- | **After Step 4** | 1400.00 | 4100.00 | 1500.00 |
-- | **After Step 6** | 1400.00 | 3500.00 | 1500.00 |
-- | **After Step 7** | 1400.00 | 3500.00 | 2100.00 |
-- | **After Step 9** | 1400.00 | 3500.00 | 2100.00 |

-- ====================================================== Task 2 =======================================================

-- A: READ UNCOMMITED

-- B: REPEATABLE READ

-- C: SERIALIZABLE

-- ====================================================== Task 3 =======================================================

BEGIN;
UPDATE inventory SET quantity = quantity - 10 WHERE product = 'Laptop';
SAVEPOINT backupl;
UPDATE inventory SET quantity = quantity + 10 WHERE product = 'Mouse';
ROLLBACK TO backupl;
COMMIT;

-- ====================================================== Task 4 =======================================================

-- Balance could be non-positive in the case of double-withdraw
-- We need to use serializable isolation level to handle this properly
