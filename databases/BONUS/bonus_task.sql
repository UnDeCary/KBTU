-- =====================================================================================================================
-- ================================================ cmtm Bonus Task LAB ================================================
-- =====================================================================================================================

-- ================================================== Database Setup ===================================================

CREATE TYPE customer_status AS ENUM ('active', 'blocked', 'frozen');
CREATE TYPE account_currency AS ENUM ('KZT', 'USD', 'EUR', 'RUB');
CREATE TYPE transaction_type AS ENUM ('transfer', 'deposit', 'withdrawal');
CREATE TYPE transaction_status AS ENUM ('pending', 'completed', 'failed', 'reversed');

CREATE TABLE customers (
    customer_id SERIAL PRIMARY KEY,
    iin VARCHAR(12) UNIQUE NOT NULL,
    full_name TEXT NOT NULL,
    phone VARCHAR(20),
    email TEXT,
    status customer_status NOT NULL DEFAULT 'active',
    created_at TIMESTAMP DEFAULT NOW(),
    daily_limit_kzt NUMERIC(15,2) DEFAULT 100000
);

CREATE TABLE accounts (
    account_id SERIAL PRIMARY KEY,
    customer_id INT REFERENCES customers(customer_id),
    account_number VARCHAR(34) UNIQUE NOT NULL,
    currency account_currency NOT NULL,
    balance NUMERIC(15,2) DEFAULT 0,
    is_active BOOLEAN DEFAULT TRUE,
    opened_at TIMESTAMP DEFAULT NOW(),
    closed_at TIMESTAMP
);

CREATE TABLE transactions (
    transaction_id SERIAL PRIMARY KEY,
    from_account_id INT REFERENCES accounts(account_id),
    to_account_id INT REFERENCES accounts(account_id),
    amount NUMERIC(15,2) NOT NULL,
    currency account_currency NOT NULL,
    exchange_rate NUMERIC(15,6),
    amount_kzt NUMERIC(15,2),
    type transaction_type NOT NULL,
    status transaction_status DEFAULT 'pending',
    created_at TIMESTAMP DEFAULT NOW(),
    completed_at TIMESTAMP,
    description TEXT
);

CREATE TABLE exchange_rates (
    rate_id SERIAL PRIMARY KEY,
    from_currency account_currency NOT NULL,
    to_currency account_currency NOT NULL,
    rate NUMERIC(12,6) NOT NULL,
    valid_from TIMESTAMP NOT NULL,
    valid_to TIMESTAMP
);

CREATE TABLE audit_log (
    log_id SERIAL PRIMARY KEY,
    table_name TEXT NOT NULL,
    record_id INT NOT NULL,
    action TEXT NOT NULL,
    old_values JSONB,
    new_values JSONB,
    changed_by TEXT,
    changed_at TIMESTAMP DEFAULT NOW(),
    ip_address VARCHAR(45)
);

INSERT INTO customers (iin, full_name, phone, email, status, daily_limit_kzt)
VALUES
    ('010101010101', 'Alikhan Tursyn', '+77010000001', 'alikhan@example.com', 'active', 200000),
    ('020202020202', 'Dana Serik', '+77020000002', 'dana@example.com', 'active', 150000),
    ('030303030303', 'Murat Bek', '+77030000003', 'murat@example.com', 'blocked', 100000),
    ('040404040404', 'Aruzhan Nur', '+77040000004', 'aruzhan@example.com', 'frozen', 120000),
    ('050505050505', 'Timur Aset', '+77050000005', 'timur@example.com', 'active', 250000),
    ('060606060606', 'Laura Zhan', '+77060000006', 'laura@example.com', 'active', 180000),
    ('070707070707', 'Dias Karim', '+77070000007', 'dias@example.com', 'active', 220000),
    ('080808080808', 'Aigerim Sule', '+77080000008', 'aigerim@example.com', 'blocked', 90000),
    ('090909090909', 'Erbolat Nurtay', '+77090000009', 'erbolat@example.com', 'active', 300000),
    ('111111111111', 'Nurlan Zhaksy', '+77110000010', 'nurlan@example.com', 'active', 160000);

INSERT INTO accounts (customer_id, account_number, currency, balance)
VALUES
    (1, 'KZ123A001', 'KZT', 500000),
    (1, 'KZ123A002', 'USD', 2000),
    (2, 'KZ223A001', 'KZT', 150000),
    (3, 'KZ323A001', 'KZT', 0),
    (4, 'KZ423A001', 'EUR', 350),
    (5, 'KZ523A001', 'KZT', 780000),
    (6, 'KZ623A001', 'USD', 5400),
    (7, 'KZ723A001', 'KZT', 90000),
    (8, 'KZ823A001', 'RUB', 12000),
    (9, 'KZ923A001', 'KZT', 450000);

INSERT INTO exchange_rates (from_currency, to_currency, rate, valid_from, valid_to)
VALUES
    ('USD','KZT', 495.25, NOW(), NULL),
    ('EUR','KZT', 540.10, NOW(), NULL),
    ('RUB','KZT', 5.20, NOW(), NULL),
    ('KZT','USD', 0.0020, NOW(), NULL),
    ('KZT','EUR', 0.00185, NOW(), NULL),
    ('KZT','RUB', 0.19, NOW(), NULL),
    ('USD','EUR', 0.92, NOW(), NULL),
    ('EUR','USD', 1.08, NOW(), NULL),
    ('USD','RUB', 92.0, NOW(), NULL),
    ('RUB','USD', 0.011, NOW(), NULL);

INSERT INTO transactions
(from_account_id, to_account_id, amount, currency, exchange_rate, amount_kzt, type, status, description)
VALUES
    (1, 3, 50000, 'KZT', 1, 50000, 'transfer', 'completed', 'Payment for services'),
    (2, 6, 200, 'USD', 495.25, 99050, 'transfer', 'completed', 'Transfer to friend'),
    (3, 1, 100000, 'KZT', 1, 100000, 'deposit', 'completed', 'Cash deposit'),
    (4, 1, 50, 'EUR', 540.10, 27005, 'transfer', 'completed', 'EUR to KZT'),
    (5, NULL, 100000, 'KZT', 1, 100000, 'withdrawal', 'failed', 'ATM error'),
    (6, 2, 300, 'USD', 495.25, 148575, 'transfer', 'completed', 'Refund'),
    (7, 1, 20000, 'KZT', 1, 20000, 'transfer', 'pending', 'Waiting approval'),
    (8, 9, 5000, 'RUB', 5.20, 26000, 'transfer', 'completed', 'Gift'),
    (9, NULL, 500000, 'KZT', 1, 500000, 'withdrawal', 'completed', 'Cash withdrawal'),
    (10, 5, 10000, 'KZT', 1, 10000, 'transfer', 'reversed', 'Reversal');

INSERT INTO audit_log
(table_name, record_id, action, old_values, new_values, changed_by, ip_address)
VALUES
    ('customers', 1, 'UPDATE', '{"status":"active"}', '{"status":"blocked"}', 'admin', '192.168.0.1'),
    ('accounts', 1, 'UPDATE', '{"balance":500000}', '{"balance":450000}', 'system', '192.168.0.2'),
    ('transactions', 1, 'INSERT', NULL, '{"amount":50000}', 'api', '10.0.0.1'),
    ('customers', 3, 'UPDATE', '{"status":"blocked"}', '{"status":"active"}', 'admin', '192.168.0.3'),
    ('accounts', 6, 'DELETE', '{"is_active":true}', NULL, 'admin', '192.168.0.4'),
    ('exchange_rates', 2, 'UPDATE', '{"rate":540.10}', '{"rate":541.00}', 'system', '192.168.0.5'),
    ('transactions', 5, 'UPDATE', '{"status":"pending"}', '{"status":"failed"}', 'system', '10.0.0.22'),
    ('customers', 8, 'DELETE', '{"status":"blocked"}', NULL, 'admin', '192.168.0.10'),
    ('accounts', 4, 'UPDATE', '{"currency":"EUR"}', '{"currency":"USD"}', 'support', '172.16.0.1'),
    ('exchange_rates', 9, 'INSERT', NULL, '{"rate":92.0}', 'system', '127.0.0.1');


-- =========================================== Task 1: Transaction Managment ===========================================

CREATE OR REPLACE FUNCTION process_transfer(
       from_account_number varchar,
       to_account_number varchar,
       amount NUMERIC,
       currency account_currency,
       description TEXT
)
RETURNS JSONB
LANGUAGE plpgsql
AS $$

    DECLARE
        v_sender_account_id INT;
        v_recipient_account_id INT;

        v_sender_customer_id INT;
        v_recipient_customer_id INT;

        v_sender_status customer_status;
        v_recipient_status customer_status;

        v_sender_account_is_active BOOLEAN;
        v_recipient_account_is_active BOOLEAN;

        v_daily_limit NUMERIC;

        v_sender_balance NUMERIC;
        v_sender_balance_in_currency NUMERIC;
        v_sender_currency account_currency;

        v_recipient_currency account_currency;

        v_exchange_rate_sender_to_cur NUMERIC := 1;
        v_exchange_rate_cur_to_recipient NUMERIC := 1;
        v_exchange_rate NUMERIC := 1;

        v_amount_kzt NUMERIC;
        v_total_today NUMERIC := 0;

        v_transaction_id INT;

        v_now TIMESTAMP := NOW();

    BEGIN

        -- USERS VALIDATION

        SELECT account_id, customer_id, balance, status, daily_limit_kzt, is_active, a.currency
        INTO v_sender_account_id, v_sender_customer_id, v_sender_balance, v_sender_status, v_daily_limit, v_sender_account_is_active, v_sender_currency
        FROM accounts a
        LEFT JOIN customers c USING (customer_id)
        WHERE account_number = from_account_number AND status IS NOT NULL
        FOR UPDATE;

        IF v_sender_account_id IS NULL THEN
            RETURN jsonb_build_object('status', 'error', 'code', 'SENDER_ACCOUNT_NOT_FOUND');
        end if;

        IF NOT v_sender_account_is_active THEN
            RETURN jsonb_build_object('status', 'error', 'code', 'SENDER_ACCOUNT_INACTIVE');
        end if;

        IF v_sender_status != 'active' THEN
            RETURN jsonb_build_object('status', 'error', 'code', 'SENDER_BLOCKED_OR_FROZEN');
        end if;

        SELECT account_id, customer_id, status, is_active, a.currency
        INTO v_recipient_account_id, v_recipient_customer_id, v_recipient_status, v_recipient_account_is_active, v_recipient_currency
        FROM accounts a
        LEFT JOIN customers c USING (customer_id)
        WHERE account_number = to_account_number
        FOR UPDATE;

        IF v_recipient_account_id IS NULL THEN
            RETURN jsonb_build_object('status', 'error', 'code', 'RECIPIENT_ACCOUNT_NOT_FOUND');
        end if;

        IF NOT v_recipient_account_is_active THEN
            RETURN jsonb_build_object('status', 'error', 'code', 'RECIPIENT_ACCOUNT_INACTIVE');
        end if;

        IF v_recipient_status != 'active' THEN
            RETURN jsonb_build_object('status', 'error', 'code', 'RECIPIENT_BLOCKED_OR_FROZEN');
        end if;

        SAVEPOINT account_validated;

        -- EXCHANGE RATES VALIDATION

        IF v_sender_currency != currency THEN
            SELECT rate into v_exchange_rate_sender_to_cur
            FROM exchange_rates
            WHERE from_currency = v_sender_currency AND to_currency = currency
                AND valid_from <= v_now AND valid_to > v_now
            ORDER BY valid_from DESC
            LIMIT 1;

            IF v_exchange_rate_sender_to_cur IS NULL THEN
                RETURN jsonb_build_object('status','error','code','NO_EXCHANGE_RATE');
            end if;

            v_sender_balance_in_currency := v_sender_balance * v_exchange_rate_sender_to_cur;
        end if;

        IF v_recipient_currency != currency THEN
            SELECT rate into v_exchange_rate_cur_to_recipient
            FROM exchange_rates
            WHERE from_currency = currency AND to_currency = v_recipient_currency
              AND valid_from <= v_now AND valid_to > v_now
            ORDER BY valid_from DESC
            LIMIT 1;

            IF v_exchange_rate_cur_to_recipient IS NULL THEN
                RETURN jsonb_build_object('status','error','code','NO_EXCHANGE_RATE');
            end if;
        end if;

        IF currency != 'KZT' THEN
            SELECT rate INTO v_exchange_rate
            FROM exchange_rates
            WHERE from_currency = currency AND to_currency = 'KZT'
              AND valid_from <= v_now AND valid_to > v_now
            ORDER BY valid_from DESC
            LIMIT 1;

            IF v_exchange_rate IS NULL THEN
                RETURN jsonb_build_object('status','error','code','NO_EXCHANGE_RATE');
            END IF;
        END IF;

        v_amount_kzt := amount * v_exchange_rate;

        SAVEPOINT exchange_rates_validated;

        -- BALANCE/AMOUNT VALIDATION

        IF v_sender_balance_in_currency < amount THEN
            RETURN jsonb_build_object('status','error','code','INSUFFICIENT_FUNDS');
        end if;

        SELECT COALESCE(SUM(amount_kzt),0)
        INTO v_total_today
        FROM transactions
        WHERE from_account_id = v_sender_account_id
          AND created_at::date = CURRENT_DATE
          AND status = 'completed';

        IF (v_total_today + v_amount_kzt) > v_daily_limit THEN
            RETURN jsonb_build_object('status','error','code','DAILY_LIMIT_EXCEEDED');
        END IF;

        SAVEPOINT amount_validated;

        BEGIN
            UPDATE accounts
            SET balance = balance - amount / v_exchange_rate_sender_to_cur
            WHERE account_id = v_sender_account_id;

            UPDATE accounts
            SET balance = balance + amount * v_exchange_rate_cur_to_recipient
            WHERE account_id = v_recipient_account_id;

        EXCEPTION
            WHEN OTHERS THEN
                INSERT INTO audit_log(table_name, record_id, action, new_values, changed_by)
                VALUES ('transactions', 0, 'ERROR', jsonb_build_object('error','TRANSFER_FAILED'), 'system');

                RETURN jsonb_build_object('status','error','code','TRANSFER_FAILED');
        END;

        INSERT INTO transactions (
            from_account_id, to_account_id, amount, currency,
            exchange_rate, amount_kzt, type, status, description, completed_at
        )
        VALUES (
            v_sender_account_id, v_recipient_account_id, amount, currency,
            v_exchange_rate, v_amount_kzt, 'transfer', 'completed',
            description, NOW()
        );

        SELECT currval(pg_get_serial_sequence('transactions', 'transaction_id'))
        INTO v_transaction_id;

        INSERT INTO audit_log(table_name, record_id, action, new_values, changed_by)
        VALUES (
           'transactions',
           v_transaction_id,
           'INSERT',
           jsonb_build_object(
                   'from', from_account_number,
                   'to', to_account_number,
                   'amount', amount,
                   'currency', currency
           ),
           'system'
       );

        RETURN jsonb_build_object(
                'status','success',
                'transaction_id', v_transaction_id,
                'amount', amount,
                'message','Transfer completed successfully'
               );

    end;

$$;

SELECT process_transfer(
    'KZ123A001',
    'KZ223A001',
    50000,
    'KZT',
    'Test payment'
);


-- ============================================ Task 2: Views for Reporting ============================================

-- View 1

CREATE OR REPLACE VIEW customer_balance_summary AS
WITH latest_rates AS (
    SELECT DISTINCT ON (from_currency)
        from_currency,
        rate
    FROM exchange_rates
    WHERE to_currency = 'KZT'
    ORDER BY from_currency, valid_from DESC
),
accounts_with_kzt AS (
    SELECT
        c.customer_id,
        c.full_name,
        c.daily_limit_kzt,
        a.account_id,
        a.account_number,
        a.currency,
        a.balance,
        COALESCE(lr.rate, 1) AS rate_to_kzt,
        a.balance * COALESCE(lr.rate, 1) AS balance_kzt
    FROM customers c
    JOIN accounts a ON c.customer_id = a.customer_id
    LEFT JOIN latest_rates lr ON lr.from_currency = a.currency
),
customer_totals AS (
    SELECT
        customer_id,
        SUM(balance_kzt) AS total_balance_kzt
    FROM accounts_with_kzt
    GROUP BY customer_id
)
SELECT
    awk.customer_id,
    awk.full_name,
    awk.account_id,
    awk.account_number,
    awk.currency,
    awk.balance,
    awk.balance_kzt,
    ct.total_balance_kzt,
    awk.daily_limit_kzt,
    CASE
        WHEN awk.daily_limit_kzt = 0 THEN NULL
        ELSE (ct.total_balance_kzt / awk.daily_limit_kzt) * 100
        END AS daily_limit_utilization_pct,
    RANK() OVER (ORDER BY ct.total_balance_kzt DESC) AS rank_by_total_balance
FROM accounts_with_kzt awk
JOIN customer_totals ct USING (customer_id)
ORDER BY rank_by_total_balance, awk.customer_id, awk.account_id;

-- View 2

CREATE OR REPLACE VIEW daily_transaction_report AS
WITH daily AS (
    SELECT
        DATE(t.created_at) AS tx_date,
        t.type,
        SUM(t.amount_kzt) AS total_volume_kzt,
        COUNT(*) AS tx_count,
        AVG(t.amount_kzt) AS avg_amount_kzt
    FROM transactions t
    WHERE t.status = 'completed'
    GROUP BY DATE(t.created_at), t.type
),
with_running AS (
    SELECT
        tx_date,
        type,
        total_volume_kzt,
        tx_count,
        avg_amount_kzt,
        SUM(total_volume_kzt) OVER (
            PARTITION BY type ORDER BY tx_date
        ) AS running_total_volume_kzt,
        SUM(tx_count) OVER (
            PARTITION BY type ORDER BY tx_date
        ) AS running_total_count,
        LAG(total_volume_kzt) OVER (PARTITION BY type ORDER BY tx_date) AS prev_volume_kzt
    FROM daily
)
SELECT
    tx_date,
    type,
    total_volume_kzt,
    tx_count,
    avg_amount_kzt,
    running_total_volume_kzt,
    running_total_count,
    CASE
        WHEN prev_volume_kzt IS NULL OR prev_volume_kzt = 0 THEN NULL
        ELSE ((total_volume_kzt - prev_volume_kzt) / prev_volume_kzt) * 100
        END AS day_over_day_growth_pct
FROM with_running
ORDER BY tx_date, type;

-- View 3

CREATE OR REPLACE VIEW suspicious_activity_view
WITH (security_barrier = true) AS
WITH base AS (
    SELECT
        t.transaction_id,
        t.from_account_id,
        t.to_account_id,
        t.amount_kzt,
        t.type,
        t.created_at,
        (t.amount_kzt > 5000000) AS is_large_transaction,
        COUNT(*) OVER ( PARTITION BY t.from_account_id, DATE_TRUNC('hour', t.created_at) ) AS hourly_tx_count,
        LAG(t.created_at) OVER ( PARTITION BY t.from_account_id ORDER BY t.created_at ) AS prev_tx_time
    FROM transactions t
    WHERE t.status = 'completed'
),
flags AS (
    SELECT
    transaction_id,
    from_account_id,
    to_account_id,
    amount_kzt,
    type,
    created_at,
    is_large_transaction,
    hourly_tx_count,
    EXTRACT(EPOCH FROM (created_at - prev_tx_time)) AS seconds_since_prev,
    CASE
        WHEN prev_tx_time IS NOT NULL AND EXTRACT(EPOCH FROM (created_at - prev_tx_time)) < 60 THEN TRUE
        ELSE FALSE
    END AS is_rapid_transfer
    FROM base
)
SELECT
    transaction_id,
    from_account_id,
    to_account_id,
    amount_kzt,
    type,
    created_at,
    is_large_transaction,
    (hourly_tx_count > 10) AS too_many_transactions_per_hour,
    is_rapid_transfer
FROM flags
WHERE is_large_transaction OR hourly_tx_count > 10 OR is_rapid_transfer
ORDER BY created_at DESC;

-- =================================== Task 3: Performance Optimization with Indexes ===================================

ANALYZE;

EXPLAIN (ANALYZE, BUFFERS, TIMING)
SELECT transaction_id, amount_kzt, to_account_id, type, created_at
FROM transactions
WHERE from_account_id = 12345
  AND status = 'completed'
  AND created_at BETWEEN '2025-01-01' AND '2025-12-31'
ORDER BY created_at DESC
LIMIT 100;

-- 1) B-Tree index
CREATE INDEX IF NOT EXISTS idx_accounts_account_number ON accounts(account_number);

-- 2) Hash index
CREATE INDEX IF NOT EXISTS idx_customers_iin_hash ON customers USING HASH (iin);

-- 3) Expression index
CREATE INDEX IF NOT EXISTS idx_customers_email_ci ON customers (LOWER(email));

-- 4) Partial index
CREATE INDEX IF NOT EXISTS idx_accounts_customer_active ON accounts (customer_id) WHERE is_active = true;

-- 5) Composite covering index
CREATE INDEX IF NOT EXISTS idx_transactions_from_status_created_cover ON transactions (from_account_id, status, created_at DESC) INCLUDE (amount_kzt, to_account_id, type);

-- 6) GIN index
CREATE INDEX IF NOT EXISTS idx_auditlog_old_jsonb_gin ON audit_log USING GIN (old_values jsonb_path_ops);

CREATE INDEX IF NOT EXISTS idx_auditlog_new_jsonb_gin ON audit_log USING GIN (new_values jsonb_path_ops);

-- 7) Composite btree
CREATE INDEX IF NOT EXISTS idx_accounts_currency_balance ON accounts (currency, balance DESC);

EXPLAIN (ANALYZE, BUFFERS, TIMING)
SELECT transaction_id, amount_kzt, to_account_id, type, created_at
FROM transactions
WHERE from_account_id = 12345
  AND status = 'completed'
  AND created_at BETWEEN '2025-01-01' AND '2025-12-31'
ORDER BY created_at DESC
LIMIT 100;


-- =================================== Task 4: Advanced Procedure - Batch Processing ===================================

CREATE OR REPLACE FUNCTION process_salary_batch(
    company_account_number VARCHAR,
    payments JSONB
)
    RETURNS JSONB
    LANGUAGE plpgsql
AS $$
DECLARE
    company_account_id INT;
    company_balance NUMERIC(15,2);
    total_batch_amount NUMERIC(15,2) := 0;
    payment JSONB;
    recipient RECORD;
    failed_details JSONB := '[]'::JSONB;
    successful_count INT := 0;
    failed_count INT := 0;
    tx_amount NUMERIC(15,2);
    iin TEXT;
    description TEXT;
BEGIN
    PERFORM pg_advisory_xact_lock(hashtext(company_account_number));

    SELECT account_id, balance
    INTO company_account_id, company_balance
    FROM accounts
    WHERE account_number = company_account_number
      AND is_active = TRUE;

    IF company_account_id IS NULL THEN
        RAISE EXCEPTION 'Company account not found or inactive';
    END IF;

    FOR payment IN SELECT * FROM jsonb_array_elements(payments)
        LOOP
            total_batch_amount := total_batch_amount + (payment->>'amount')::NUMERIC;
        END LOOP;

    IF total_batch_amount > company_balance THEN
        RAISE EXCEPTION 'Insufficient funds in company account. Total batch amount: %, available: %', total_batch_amount, company_balance;
    END IF;

    FOR payment IN SELECT * FROM jsonb_array_elements(payments)
        LOOP
            iin := payment->>'iin';
            tx_amount := (payment->>'amount')::NUMERIC;
            description := payment->>'description';

            SAVEPOINT sp_payment;

            BEGIN
                SELECT a.account_id, a.is_active
                INTO recipient
                FROM accounts a
                         JOIN customers c ON c.customer_id = a.customer_id
                WHERE c.iin = iin
                  AND a.is_active = TRUE
                LIMIT 1;

                IF NOT FOUND THEN
                    failed_details := failed_details || jsonb_build_object(
                            'iin', iin,
                            'amount', tx_amount,
                            'description', description,
                            'error', 'Recipient account not found or inactive'
                                                        );
                    failed_count := failed_count + 1;
                    ROLLBACK TO SAVEPOINT sp_payment;
                    CONTINUE;
                END IF;

                UPDATE accounts
                SET balance = balance - tx_amount
                WHERE account_id = company_account_id;

                UPDATE accounts
                SET balance = balance + tx_amount
                WHERE account_id = recipient.account_id;

                INSERT INTO transactions(
                    from_account_id,
                    to_account_id,
                    amount,
                    currency,
                    amount_kzt,
                    type,
                    status,
                    description,
                    created_at,
                    completed_at,
                    exchange_rate
                )
                VALUES (
                    company_account_id,
                    recipient.account_id,
                    tx_amount,
                    'KZT',
                    tx_amount,
                    'transfer',
                    'completed',
                    description,
                    NOW(),
                    NOW(),
                    1
                       );

                successful_count := successful_count + 1;

            EXCEPTION WHEN OTHERS THEN
                failed_details := failed_details || jsonb_build_object(
                    'iin', iin,
                    'amount', tx_amount,
                    'description', description,
                    'error', SQLERRM
                    );
                failed_count := failed_count + 1;
                ROLLBACK TO SAVEPOINT sp_payment;
            END;
        END LOOP;

    RETURN jsonb_build_object(
        'successful_count', successful_count,
        'failed_count', failed_count,
        'failed_details', failed_details
       );
END;
$$;
