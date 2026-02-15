package com.zlup.practice2;

public class Main {

    public static void main(String[] args) {
        // Task 1
        Student student = new Student("Ilya", "24B032008", 2);

        System.out.println("Name: " + student.getName());
        System.out.println("ID: " + student.getId());
        System.out.println("Year: " + student.getYearOfStudy());

        System.out.println("After promotion, year: " + student.increaseYearOfStudy());

        // Task 2
        StarTriangle triangle = new StarTriangle(5);
        System.out.print(triangle);

        // Task 3
        Time t1 = new Time(23, 9, 34);
        Time t2 = new Time(23, 9, 34);
        System.out.println(t1.toUniversal());
        System.out.println(t1.toStandard());

        t1.add(t2);
        System.out.println(t1.toUniversal());
        System.out.println(t1.toStandard());
    }
}
