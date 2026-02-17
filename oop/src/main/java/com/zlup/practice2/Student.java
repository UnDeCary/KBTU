package com.zlup.practice2;

public class Student {
    private String name;
    private int id;
    private int yearOfStudy;

    private static int cnt = 0;

    public Student(String name, int yearOfStudy) {
        this.name = name;
        this.id = ++cnt;
        this.yearOfStudy = yearOfStudy;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public int getYearOfStudy() {
        return yearOfStudy;
    }

    public int increaseYearOfStudy() {
        return ++yearOfStudy;
    }
}
