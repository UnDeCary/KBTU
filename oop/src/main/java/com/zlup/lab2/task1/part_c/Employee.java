package com.zlup.lab2.task1.part_c;

import java.util.Objects;

public class Employee extends Person {
    private String employeeId;

    private String getEmployeeId() {
        return employeeId;
    }

    public void setEmployeeId(String employeeId) {
        this.employeeId = employeeId;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null)
            return false;

        if (!(obj instanceof Person))
            return false;

        Employee employee = (Employee) obj;

        if (this.employeeId == employee.employeeId)
            return true;


        return false;
    }

    @Override
    public int hashCode() {
        return Objects.hash(employeeId);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Name: " + getName());
        sb.append("Age: " + getAge());
        sb.append("Employee Id: " + getEmployeeId() + "\n");
        return sb.toString();
    }

}
