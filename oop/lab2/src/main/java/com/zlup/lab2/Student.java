package com.zlup.lab2;

public class Student {
    private String name;
    private String id;
    private int yearOfStudy;

    public Student(String name, String id, int yearOfStudy) {
        this.name = name;
        this.id = id;
        this.yearOfStudy = yearOfStudy;
    }

    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }

    public int getYearOfStudy() {
        return yearOfStudy;
    }

    public int increaseYearOfStudy() {
        return ++yearOfStudy;
    }
}
