package com.zlup.practice4.problem4;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Student> students = new ArrayList<>();
        students.add(new Student("Ilya", 3.5));
        students.add(new Student("Artem", 3.9));
        students.add(new Student("Sarvan", 3.2));

        Collections.sort(students);
        System.out.println("GPA sort:");
        for (Student s : students) {
            System.out.println(s);
        }

        Collections.sort(students, new NameComparator());
        System.out.println("Name sort:");
        for (Student s : students) {
            System.out.println(s);
        }
    }
}
