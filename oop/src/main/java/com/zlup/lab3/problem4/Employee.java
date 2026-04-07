package com.zlup.lab3.problem4;

import java.util.Date;

public class Employee extends Person implements Comparable<Employee>, Cloneable {
    private double salary;
    private Date hireDate;
    private String insuranceNumber;

    public Employee(String name, double salary, Date hireDate, String insuranceNumber) {
        super(name);
        this.salary = salary;
        this.hireDate = hireDate;
        this.insuranceNumber = insuranceNumber;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public Date getHireDate() {
        return hireDate;
    }

    public void setHireDate(Date hireDate) {
        this.hireDate = hireDate;
    }

    public String getInsuranceNumber() {
        return insuranceNumber;
    }

    public void setInsuranceNumber(String insuranceNumber) {
        this.insuranceNumber = insuranceNumber;
    }


    @Override
    public String toString() {
        return super.toString() + "\nSalary: " + salary + "\n Hired: " + hireDate + "\nInsurance Number: " + insuranceNumber;
    }

    @Override
    public int compareTo(Employee other) {
        return Double.compare(this.salary, other.salary);
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof  Employee)) {return false;}
        return this.salary == ((Employee) o).salary;
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}
