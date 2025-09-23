
# Task 1.1: Superkey and Candidate Key Analysis

## Relation A: Employee

| EmpID | SSN         | Email            | Phone    | Name | Department | Salary |
| ----- | ----------- | ---------------- | -------- | ---- | ---------- | ------ |
| 101   | 123-45-6789 | john@company.com | 555-0101 | John | IT         | 75000  |
| 102   | 987-65-4321 | mary@company.com | 555-0102 | Mary | HR         | 68000  |
| 103   | 456-78-9123 | bob@company.com  | 555-0103 | Bob  | IT         | 72000  |

### 1 )  6 different superkeys

 - EmpID
 - SSN
 - Email
 - Phone
 - EmpID + SSN
 - EmpID + Phone

### 2 ) All candidate keys

- EmpID
- SSN
- Email
- Phone

### 3 ) Primary key

- **EmpID** - Easy to autoincrement and easy to use as foreign key

### 4 ) Can two employees have same phone number?

- According to the data shown - **NO**
 


## Relation B: Course Registration

### 1 ) Minimum attributes for the primary key

- StudentID
- CourseCode
- Section
- Semester
- Year

### 2 ) Why each attribute in primary key is necessary

- **StudentID** - Helps to identify which student is registrated
- **CourseCode** - Helps to distinguish between different courses.
- **Section** - a student can only take one section of the same course per semester.
- **Semester** - the same course can be offered in multiple semesters.
- **Year** - the same semester (e.g., Fall) repeats across different years.

> Without any of these attributes, uniqueness of registrations would be lost.

### 3 ) Additional candidate keys

There is no additional candidate keys



# Task 1.2: Foreign Key Design

### Identify all foreign key relationships


#### Student

| StudentID | Name    | Email   | Major          | AdvisorID  |
| --------- | ------- | ------- | -------------- | ---------- |
| int PK    | varchar | varchar | varchar **FK** | int **FK** |
**Foreign key**s - ( Student.AdvisorID -> Professor.ProfID )
**Foreign key**s - ( Student.Major -> Department.DeptCode )

#### Professor

| ProfID | Name    | Department     | Salary |
| ------ | ------- | -------------- | ------ |
| int PK | varchar | varchar **FK** | int    |
**Foreign key** - ( Professor.Department -> Department.DeptCode )

#### Course

| CourseID | Title   | Credits | DepartmentCode |
| -------- | ------- | ------- | -------------- |
| int PK   | varchar | int     | varchar **FK** |
**Foreign key** - ( Course.DepartmentCode -> Department.DeptCode )

#### Department

| DeptCode   | DeptName | Budget | ChairID    |
| ---------- | -------- | ------ | ---------- |
| varchar PK | varchar  | int    | int **FK** |
**Foreign key** - ( Department.ChairID -> Professor.ProfID )

#### Enrollment

| StudentID  | CourseID   | Semester | Grade |
| ---------- | ---------- | -------- | ----- |
| int **FK** | int **FK** | varchar  | int   |
**Foreign keys** - ( Enrollment.StudentID -> Student.StudentID )
**Foreign keys** - ( Enrollment.CourseID -> Course.CourseID )



# Task 2.1: Hospital Management System

#### 1.
Strong Entities
- Patient
- Doctor
- Department
- Appointment
- Prescription
- Room

Weak Entities:
- Phone
- Specialization

#### 2.
##### Patient

- **PatientID** (PK, simple)
- **Name** (simple)
- **Birthdate** (simple)
- **Address** (composite: Street, City, State, Zip)
- **Phone** (multi-valued)
- **InsuranceInfo** (simple)

##### Doctor

- **DoctorID** (PK, simple)
- **Name** (simple)
- **Specializations** (multi-valued)
- **PhoneNumbers** (multi-valued)
- **OfficeLocation** (simple)

##### Department

- **DeptCode** (PK, simple)
- **DeptName** (simple)
- **Location** (simple)

##### Appointment

- **AppointmentID** (PK, simple)
- **PatientID** (FK -> Patient)
- **DoctorID** (FK -> Doctor)
- **DateTime** (simple)
- **Purpose** (simple)
- **Notes** (simple)

##### Prescription

- **PrescriptionID** (PK, simple)
- **DoctorID** (FK -> Doctor)
- **PatientID** (FK -> Patient)
- **Medication** (simple)
- **Dosage** (simple)
- **Instructions** (simple)

##### Room

- **RoomNumber** (PK-partial)
- **DeptCode** (FK -> Department, PK-partial)
- **Full PK = (DeptCode, RoomNumber)**


### 3.

##### 1) Patient - Appointment - Doctor
- One patient can have many appointments (1:N)
- One doctor can have many appointments (1:N)
- Relationship **M:N** within entity **Appointment**
##### 2) Doctor - Prescription - patient
- One doctor can make many prescriptions (1:N)
- One patient can receive many prescriptions (1:N)
- Relationship **M:N** within entity **Prescription**
##### 3) Department - Doctor
- One department can consist many doctors (1:N)
##### 4) Department - Room
 - One department can consist many rooms (1:N)
#### 4-5
 [[Task 2.1.canvas|ER Diagram]]


# Task 2.2: E-commerce Platform

##### 1) [[Task 2.2.canvas|ER Diagram]]

##### 2) Weak entities
- **OrderItem** - The existance of entity depends on Order and Product
- **Review** - Without Customer and Product it is useless

##### 3) Relationships
- **Customer - Order**: 1:N (one customer can place many orders).
- **Order - OrderItem - Product**: M:N via weak entity **OrderItem** (an order can have many products, and a product can appear in many orders).
- **Product - Category**: M:1 (each product belongs to one category).
- **Product - Vendor**: M:1 (each product is supplied by one vendor).
- **Product - Review - Customer**: M:N via **Review** (a product can have many reviews, and a customer can write many reviews).


# Task 4.1: Denormalized Table Analysis

##### 1) Functional dependencies
- StudentID -> StudentName, StudentMajor
- ProjectID -> ProjectTitle, ProjectType, SupervisorID
- SupervisorID -> SupervisorName, SupervisorDept
- (StudentID, ProjectID) -> Role, HouseWorked, StartDate, EndDate
##### 2) Problems in table
1. **Redundancy**: 
	- Duplicates of student name if student participate in multiple projects
	- Info about supervisor duplicates
	- ProjectTitle and ProjectType duplicates
2. **Anomalies**:
	- **Update**: If supervisor change department, we have to update it in all rows
	- **Insert**: We can't add project without student
	- **Delete**: if we delete student from project - we delete project

##### 3) 1NF
- Already in 1NF
- No violations

##### 4) 2NF
 **Primary key**
- (StudentID, ProjectID)
**Partial Dependencies**
- **StudentID -> StudentName, StudentMajor**
- **ProjectID -> ProjectTitle, ProjectType, SupervisorID**

**2NF Decomposition**

1. **Student(StudentID, StudentName, StudentMajor)**
2. **Project(ProjectID, ProjectTitle, ProjectType, SupervisorID)**
3. **StudentProject(StudentID, ProjectID, Role, HoursWorked, StartDate, EndDate)**


##### 5) 3NF

**Transitive Dependencies**:
- **SupervisorID** -> SupervisorName, SupervisorDept

**3NF Decomposition**
- **Student(StudentID, StudentName, StudentMajor)**
- **Supervisor(SupervisorID, SupervisorName, SupervisorDept)**
- **Project(ProjectID, ProjectTitle, ProjectType, SupervisorID)**
- **StudentProject(StudentID, ProjectID, Role, HoursWorked, StartDate, EndDate)**


# Task 4.2: Advanced Normalization

##### 1) Primary key
- (StudentID, CourseID, TimeSlot, Room)

##### 2) FD
- StudentID -> StudentMajor (student have 1 major)
- CourseID -> CourseName (course has 1 name)
- InstructorID -> InstructorName (instructor has 1 name)
- Room -> Building
- (CourseID, TimeSlot, Room) -> InstructorID (Section has instructor)

##### 3) BCNF Check

- StudentID -> StudentMajor - violate (StudentID is not superkey)
- CourseID -> CourseName - violate (CourseID is not superkey)
- Table is not in BCNF

##### 4) Decompose
- Student(StudentID PK, StudentMajor)
- Course(CourseID PK, CourseName)
- Instructor(InstructorID PK, InstructorName)
- Room(Room PK, Building)
- CourseSection(CourseID, TimeSlot, Room, InstructorID)
- Enrollment(StudentID, CourseID, TimeSlot, Room)

##### 4) Loss of info
- There is no info loss: We can restor original table by joining all tables
- Functional depenancy are saved: every dependency separated by tables
