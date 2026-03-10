package com.zlup.lab2.task5;

public class Employee extends Person {

    private String profession;

    public Employee(String name, int age, String profession) {
        this.profession = profession;
        this.name = name;
        this.age = age;
    }

    public String getOccupation() {
        return "Employee: " + profession;
    }

}
