package com.zlup.lab1;

import java.util.Vector;

public class Course {
    public String name;
    public String description;
    public int numberOfCredits;
    public Vector<Course> prerequisites;

    public Course(String name, String description, int numberOfCredits, Vector<Course> prereq) {
        this.name = name;
        this.description = description;
        this.numberOfCredits = numberOfCredits;
        this.prerequisites = prereq;
    }
}
