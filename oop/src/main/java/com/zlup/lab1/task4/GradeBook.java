package com.zlup.lab1.task4;

import com.zlup.practice2.Student;

import java.util.Map;

public class GradeBook {
    private final Course course;
    private final Map<Student, Integer> gradeList;

    public GradeBook(Course course, Map<Student, Integer> gradeList) {
        this.course = course;
        this.gradeList = gradeList;
    }

    public void displayMessage() {
        System.out.println("Welcome to the gradebook of " + course.name);
    }

    private double getAverage() {
        int sum = 0, count = 0;
        for (Integer value : gradeList.values()) {
            sum += value;
            count++;
        }

        return (double) (sum / count);
    }

    private String getLowest() {
        int lowest = 101;
        Student student = null;// = new Student("Null", -1);
        for (Student key : gradeList.keySet()) {
            if (gradeList.get(key) < lowest) {
                lowest = gradeList.get(key);
                student = key;
            }
        }

        assert student != null;
        return "Lowest grade is " + lowest + " ( " + student.getName() + " )";
    }

    private String getHighest() {
        int highest = -1;
        Student student = null;
        for (Student key : gradeList.keySet()) {
            if (gradeList.get(key) > highest) {
                highest = gradeList.get(key);
                student = key;
            }
        }

        assert student != null;
        return "Highest grade is " + highest + " ( " + student.getName() + " )";
    }

    public String getBarDistribution() {
//        String res = "Grades distribution:\n";
        StringBuilder sb = new StringBuilder();
        int[] distribution = new int[11];

        sb.append("Grades distribution:\n");

        for (Integer value : gradeList.values()) {
            distribution[value/10]++;
        }

        for (int i = 0; i < distribution.length; i++) {
            int from = i * 10;
            int to = from + 9;

            StringBuilder stringBuilder = from != 100 ? sb.append(from + "-" + to + ": ") : sb.append(from + ": ");

            sb.append("*".repeat(distribution[i]) + "\n");

        }

        return sb.toString();

    }

    public void displayGradeReport() {
        System.out.println("Class average is " + getAverage());
        System.out.println(getLowest());
        System.out.println(getHighest());
        System.out.print(getBarDistribution());
    }
}
