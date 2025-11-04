-- ============================================= Part 1: Check Constraints =============================================

-- Task 1.1
/home/zlup/projects
CREATE TABLE employees (
    employee_id int,
    first_name text,
    last_name text,
    age int check (age between 18 and 65),
    salary numeric check (salary > 0)
);

-- Task 1.2

CREATE TABLE products_catalog (
    product_id int,
    product_name text,
    regular_price numeric,
    discount_price numeric,

    constraint valid_discount check (regular_price > 0 and discount_price > 0 and discount_price < regular_price)
);

-- Task 1.3

CREATE TABLE bookings (
    booking_id int,
    check_in_date date,
    check_out_date date,
    num_guests int check (num_guests between 1 and 10),
    constraint valid_date check (check_in_date < check_out_date)
);

-- Task 1.4

-- 1
INSERT INTO employees (employee_id, first_name, last_name, age, salary)
VALUES
    (1, 'John', 'Doe', 30, 3500.00),
    (2, 'Alice', 'Smith', 45, 5200.00);

INSERT INTO products_catalog (product_id, product_name, regular_price, discount_price)
VALUES
    (1, 'Wireless Mouse', 25.99, 19.99),
    (2, 'Mechanical Keyboard', 79.99, 59.99);

INSERT INTO bookings (booking_id, check_in_date, check_out_date, num_guests)
VALUES
    (1, '2025-10-20', '2025-10-25', 2),
    (2, '2025-11-01', '2025-11-05', 4);

-- 2
INSERT INTO employees
VALUES (3, 'Bob', 'Black', 17, 3500.00); -- violates age
INSERT INTO employees
VALUES (3, 'Bob', 'Black', 32, 0); -- violates salary

INSERT INTO products_catalog
VALUES (3, 'Wireless Headphones', 0, 0); -- regular and discount price not > 0
INSERT INTO products_catalog
VALUES (3, 'Wireless Headphones', 200, 250); -- regular < discount

INSERT INTO bookings
VALUES (3, '2025-11-01', '2025-11-05', 0); -- violates 1 <= num guests <= 10
INSERT INTO bookings
VALUES (3, '2025-11-06', '2025-11-05', 2); -- violates date

-- =========================================== Part 2: Not Null Constraints ============================================

-- Task 2.1

CREATE TABLE customers (
    customer_id int not null,
    email text not null,
    phone text,
    registration_date date not null
);

-- Task 2.2

CREATE TABLE inventory (
    item_id int not null,
    item_name text not null,
    quantity int not null check ( quantity >= 0 ),
    unit_price numeric not null check ( unit_price > 0),
    last_update timestamp not null
);

-- Task 2.3

INSERT INTO customers (customer_id, email, phone, registration_date)
VALUES
    (1, 'john.doe@example.com', '+777831278264', '2025-10-15'),
    (2, 'alice.smith@example.com', NULL, '2025-10-16');

INSERT INTO inventory (item_id, item_name, quantity, unit_price, last_updated)
VALUES
    (1, 'Laptop', 5, 1200.00, NOW()),
    (2, 'Mouse', 50, 20.00, NOW());

INSERT INTO customers (customer_id, email, phone, registration_date)
VALUES (3, NULL, '+77783127826', '2025-10-17');

INSERT INTO inventory (item_id, item_name, quantity, unit_price, last_updated)
VALUES (3, 'Keyboard', NULL, 40.00, NOW());

INSERT INTO customers (customer_id, email, phone, registration_date)
VALUES (4, 'mike.jones@example.com', NULL, '2025-10-18');

-- ============================================ Part 3: Unique Constraints =============================================

-- Task 3.1

CREATE TABLE users (
    user_id int,
    username text unique,
    email text unique,
    created_at timestamp
);

-- Task 3.2

CREATE TABLE course_enrollments (
    enrollment_id int,
    student_id int,
    course_code text,
    semester text,
    constraint unique_combination unique (student_id, course_code, semester)
);

-- Task 3.3

ALTER TABLE users
ADD CONSTRAINT unique_username UNIQUE (username),
ADD CONSTRAINT unique_email UNIQUE (email);

INSERT INTO users (user_id, username, email)
VALUES (1, 'alex', 'alex@example.com');

INSERT INTO users (user_id, username, email)
VALUES (2, 'alex', 'another@example.com');

INSERT INTO users (user_id, username, email)
VALUES (3, 'mike', 'alex@example.com');

-- ========================================== Part 4: Primary Key Constraints ==========================================

-- Task 4.1

CREATE TABLE departments (
    dept_id int primary key,
    dept_name text not null,
    location text
);

INSERT INTO departments (dept_id, dept_name, location)
VALUES
    (1, 'SAM', '2nd floor'),
    (2, 'ISE', '4th floor'),
    (3, 'SITE', '1st floor');


INSERT INTO departments (dept_id, dept_name, location)
VALUES (1, 'Marketing', 'Paris');


INSERT INTO departments (dept_id, dept_name, location)
VALUES (NULL, 'SCE', '3rd floor');

-- Task 4.2

CREATE TABLE student_courses (
    student_id int,
    course_id int,
    enrollment_date date,
    grade text,
    constraint primary_key_pair primary key (student_id, course_id)
);


-- Task 4.3

-- Primary key is unique and not null | only 1 pk per table
-- single pk makes column unique | composite pk makes pair of columns unique
-- PK - main identifier | unique - constraint to values be unique


-- ========================================== Part 5: Foreign Key Constraints ==========================================

-- Task 5.1

CREATE TABLE employees_dept (
    emp_id int primary key,
    emp_name text not null,
    dept_id int references departments,
    hire_date date
);

INSERT INTO employees_dept
VALUES (1, "Ski", 1, '2020-02-24');

INSERT INTO employees_dept
VALUES (2, "Ski", 7, '2020-02-24');

-- Task 5.2

CREATE TABLE authors (
    author_id int primary key,
    author_name text not null,
    country text
);

CREATE TABLE publishers (
    publisher_id int primary key,
    publisher_name text not null,
    city text
);

CREATE TABLE books (
    book_id int primary key,
    title text not null,
    author_id int references authors,
    publisher_id int references publishers,
    publication_year int,
    isbn text unique
);

INSERT INTO authors (author_id, author_name, country)
VALUES
    (1, 'George Orwell', 'United Kingdom'),
    (2, 'Haruki Murakami', 'Japan'),
    (3, 'Gabriel García Márquez', 'Colombia');

INSERT INTO publishers (publisher_id, publisher_name, city)
VALUES
    (1, 'Penguin Books', 'London'),
    (2, 'Vintage', 'Tokyo'),
    (3, 'HarperCollins', 'New York');

INSERT INTO books (book_id, title, author_id, publisher_id, publication_year, isbn)
VALUES
    (1, '1984', 1, 1, 1949, '9780451524935'),
    (2, 'Kafka on the Shore', 2, 2, 2002, '9781400079278'),
    (3, 'One Hundred Years of Solitude', 3, 3, 1967, '9780060883287');

-- Task 5.3

CREATE TABLE categories (
    category_id int primary key,
    category_name text not null
);

CREATE TABLE products_fk (
    product_id int primary key,
    product_name text not null,
    category_id int references  categories on delete restrict
);

CREATE TABLE orders (
    order_id int primary key,
    order_date date not null
);

CREATE TABLE order_items (
    item_id int primary key,
    order_id int references orders on delete cascade,
    product_id int references products_fk,
    quantity int check (quantity > 0)
);

INSERT INTO categories (category_id, category_name) VALUES
    (1, 'Electronics'),
    (2, 'Books');

INSERT INTO products_fk (product_id, product_name, category_id) VALUES
    (1, 'Smartphone', 1),
    (2, 'Laptop', 1),
    (3, 'Novel', 2);

INSERT INTO orders (order_id, order_date) VALUES
    (1, '2025-10-15'),
    (2, '2025-10-16');

INSERT INTO order_items (item_id, order_id, product_id, quantity) VALUES
    (1, 1, 1, 2),
    (2, 1, 2, 1),
    (3, 2, 3, 5);

DELETE FROM categories WHERE category_id = 1;

DELETE FROM orders WHERE order_id = 1;

SELECT * FROM orders;
SELECT * FROM order_items;

-- =========================================== Part 6: Practical Application ===========================================

-- Task 6.1

CREATE TABLE customers (
    customer_id serial primary key,
    name text not null,
    email text unique not null,
    phone text unique not null,
    registration_date date not null
);

CREATE TABLE products (
    product_id serial primary key,
    name text not null,
    description text,
    price int not null check (price >= 0),
    stock_quantity int not null check (stock_quantity >= 0)
);

CREATE TABLE orders(
    order_id serial primary key,
    customer_id int references customers ON DELETE CASCADE,
    order_date date not null,
    total_amount int not null check (total_amount > 0),
    status text not null check(status in ('pending', 'processing', 'shipped', 'delivered', 'cancelled'))
);

CREATE TABLE order_details (
    order_detail_id serial primary key,
    order_id int references orders,
    product_id int references products,
    quantity int not null check(quantity > 0),
    unit_price int not null check(unit_price > 0)
);


-- In-Class Practice

-- Task 1

CREATE TABLE categories (
    category_id int primary key,
    category_name text not null unique,
    description text,
    is_active bool not null default true
);

CREATE TABLE instructors (
    instructor_id int primary key,
    username text not null unique,
    email text not null unique,
    full_name text not null,
    bio text,
    hourly_rate numeric check (hourly_rate between 15 and 500),
    rating numeric check (rating between 0.0 and 5.0),
    total_students int not null default 0 check (total_students >= 0),
    joined_date date not null default NOW(),
);

INSERT INTO categories
VALUES (1, 'Programming'),
       (2, 'Design'),
       (3, 'Business');

INSERT INTO instructors
VALUES
    (1, 'j_smith', 'j_smith@shop.com', 'John Smith', null, 400, 4.2, 15),
    (2, 's_black', 's_black@shop.com', 'Sam Black', null, 330, 3.8, 12),
    (3, 'w_white', 'w_white@shop.com', 'Walter White', null, 420, 4.9, 20);


INSERT INTO instructors
VALUES (4, 'b_con', 'b_con@shop.com', 'Bob Con', null , 490, 6.0, 12);

INSERT INTO instructors
VALUES (4, 's_black', 'b_con@shop.com', 'Bob Con', null , 490, 3.0, 12);


INSERT INTO instructors
VALUES (4, 'b_con', 'b_con@shop.com', 'Bob Con', null , 10, 3.0, 12);

-- Task 2

CREATE TABLE courses (
    course_id int primary key,
    course_title text not null,
    instructor_id int not null references instructors on delete restrict,
    category_id int not null references categories on delete restrict,
    description text not null,
    level text not null check (level in ('beginner', 'intermediate', 'advanced', 'expert')),
    regular_price numeric not null check (regular_price between 9.99 and 999.99),
    sale_price numeric check (sale_price is null or (sale_price < regular_price and sale_price >= 0)),
    duration_hours numeric not null check (duration_hours between 0.5 and 200),
    max_students int check (max_students is null or max_students between 10 and 1000),
    enrollment_count int not null default false,
    is_published bool not null default false,
    create_date date not null default NOW(),
    constraint unique_pair unique (course_id, instructor_id)
);



-- Task 3

CREATE TABLE students (
    student_id int primary key,
    username text not null unique,
    email text not null unique,
    full_name text not null,
    date_of_birth date not null,
    registration_date date not null default NOW(),
    account_balance numeric not null default 0,
    total_courses_completed int not null default 0 check (total_courses_completed >= 0),
    subscription_type text not null default 'free' check (subscription_type in ('free', 'monthly', 'annual', 'lifetime')),

    constraint more_than_13_yo check (EXTRACT(YEAR FROM AGE(NOW(), date_of_birth)) > 13),
    constraint registration_not_in_future check ( registration_date < NOW() )
);


-- Task 4

CREATE TABLE enrollments (
    student_id int references students on delete cascade,
    course_id int references courses on delete restrict,
    enrollment_date timestamp not null default NOW(),
    price_paid numeric not null  check (price_paid >= 0),
    progress_percentage numeric not null default 0 check (progress_percentage between 0 and 100),
    status text not null default 'active' check (status in ('active', 'completed', 'dropped', 'refunded')),
    completion_date date,
    certificate_isssued bool not null default false,
    constraint pk_1 primary key (student_id, course_id),

)