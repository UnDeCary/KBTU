-- 1.1: Database Creation with Parameters
create database university_main owner postgres template template0 encoding 'UTF8';
create database university_archive connection limit 50 template template0;
create database university_test template template0 connection limit 10;
update pg_database set datistemplate = true where datname = 'university_test';

-- 1.2: Tablespace Operations
create tablespace student_data location 'C:\\pg_tablespaces\\students'; -- '/data/students';
create tablespace course_data owner postgres location 'C:\\pg_tablespaces\\courses';  -- '/data/courses';
create database university_distributed template template0 tablespace student_data encoding 'LATIN9' LC_CTYPE 'C' LC_COLLATE 'C';

-- 2.1: University Management System
create table students (
	student_id serial primary key,
	first_name varchar(50),
	last_name varchar(50),
	email varchar(100),
	phone char(15),
	date_of_birth date,
	enrollment_date date,
	gpa decimal(3, 2),
	is_active bool,
	graduation_year smallint
);

create table professors (
	professor_id serial primary key,
	first_name varchar(50),
	last_name varchar(50),
	email varchar(100),
	office_number varchar(20),
	hire_date date,
	salary decimal (12,2),
	is_tenured bool,
	years_experience int
);

create table courses (
	course_id serial primary key,
	course_code char(8),
	course_title varchar(100),
	description text,
	credits smallint,
	max_enrollment int,
	course_fee decimal(10, 2),
	is_online bool,
	created_at timestamp without time zone
);

-- 2.2: Time-based and Specialized Tables
create table class_schedule (
	schedule_id serial primary key,
	corse_id int,
	professor_id int,
	classroom varchar(20),
	class_date date,
	start_time time without time zone,
	end_time time without time zone,
	duration interval
);

create table student_records (
	record_id serial primary key,
	student_id int,
	course_id int,
	semester varchar(20),
	year int,
	grade char(2),
	attendance_percentage decimal(4,1),
	submission_timestamp timestamp with time zone,
	last_updated timestamp with time zone
);

--  3.1: Modifying Existing Tables
alter table students 
	add column middle_name varchar(30),
	add column student_status varchar(20) default 'ACTIVE',
	alter column phone type varchar(20),
	alter column gpa set default 0.00;

alter table professors 
	add column department_code char(5),
	add column research_area text,
	add column last_promotion_date date,
	alter column years_experience type smallint,
	alter column is_tenured set default false;

alter table courses
	add column prerequisite_course_id int,
	add column difficulty_level smallint,
	alter column course_code type varchar(10),
	alter column credits set default 3,
	add column lab_required bool default false;

-- 3.2: Column Management Operations
alter table class_schedule
	add column room_capacity int,
	drop column duration,
	add column session_type varchar(15),
	alter column classroom type varchar(30),
	add column equipment_needed text;

alter table student_records
	add column extra_credit_points decimal(4, 1) default 0.0,
	alter column grade type varchar(5),
	add column final_exam_date date,
	drop column	last_updated;

-- 4.1: Additional Supporting Tables
create table departments (
	department_id serial primary key,
	department_name varchar(100),
	department_code char(5),
	building varchar(50),
	phone varchar(15),
	budget decimal(12, 2),
	established_year int
);

create table library_books (
	book_id serial primary key,
	isbn char(13),
	title varchar(200),
	author varchar(100),
	publisher varchar(100),
	publication_date date,
	price decimal(10, 2),
	is_available bool,
	acquisition_timestamp timestamp without time zone
);

create table student_book_loans (
	loan_id serial primary key,
	student_id int,
	book_id int,
	loan_date date,
	due_date date,
	return_date date,
	fine_amount decimal(10, 2),
	loan_status varchar(20)
);

-- 4.2: Table Modifications for Integration
alter table professors
	add column department_id int;
	
alter table students
	add column advisor_id int;
	
alter table courses
	add column department_id int;

create table grade_scale (
	grade_id serial primary key,
	letter_grade char(2),
	min_percentage decimal(4, 1),
	max_percentage decimal(4, 1),
	gpa_points decimal(5,2)
);

create table semester_calendar (
	semester_id serial primary key,
	semester_name varchar(20),
	academic_year int,
	start_date date,
	end_date date,
	registration_deadline timestamp with time zone,
	is_current bool
);

-- 5.1: Conditional Table Operations
drop table if exists student_book_loans;
drop table if exists library_books;
drop table if exists grade_scale;

create table grade_scale (
	grade_id serial primary key,
	letter_grade char(2),
	min_percentage decimal(4, 1),
	max_percentage decimal(4, 1),
	gpa_points decimal(5,2),
	descriprion text
);

drop table if exists semester_calendar cascade;

create table semester_calendar (
	semester_id serial primary key,
	semester_name varchar(20),
	academic_year int,
	start_date date,
	end_date date,
	registration_deadline timestamp with time zone,
	is_current bool
);

-- 5.2: Database Cleanup
update pg_database set datistemplate = false where datname = 'university_test';
drop database if exists university_test;
drop database if exists university_distributed;
create database university_backup
	with template = university_main
	owner postgres;

