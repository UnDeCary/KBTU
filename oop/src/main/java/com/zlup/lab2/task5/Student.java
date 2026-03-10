package com.zlup.lab2.task5;

public class Student extends Person {

    private String major;

    public Student(String name, int age, String major) {
        this.name = name;
        this.age = age;
        this.major = major;
    }

    public String getOccupation() {
        return "Student: " + name;
    }
}
