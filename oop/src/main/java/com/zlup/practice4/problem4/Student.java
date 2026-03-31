package com.zlup.practice4.problem4;

public class Student implements Comparable<Student>{
    private String name;
    private double age;

    public Student(String name, double age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    @Override
    public int compareTo(Student o) {
        return Double.compare(this.age, o.age);
    }

    @Override
    public String toString() {
        return "Student [name=" + name + ", age=" + age + "]";
    }
}
