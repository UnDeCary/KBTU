package com.zlup.lab2.task1;

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

        Employee employee = (Employee) obj;

        if (this.employeeId == employee.employeeId)
            return true;

        if (getClass() != obj.getClass())
            return false;
        return false;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 97 * hash + Objects.hashCode(this.employeeId);
        return hash;
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
