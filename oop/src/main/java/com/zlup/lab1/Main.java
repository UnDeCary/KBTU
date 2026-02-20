package com.zlup.lab1;

import com.zlup.lab1.task2.*;
import com.zlup.lab1.task3.*;
import com.zlup.lab1.task4.*;
import com.zlup.lab1.task5.*;
import com.zlup.practice2.Student;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {

        // TASK 2

        Car car1 = new Car("VIN123", "Porsche 911 GT3RS", EngineType.ELECTIC);
        Car car2 = new Car("VIN456", "Ford Mustang", EngineType.PETROL);

        System.out.println(car1.getModel() + " has VIN " + car1.getVin() + " and engine " + car1.getEngineType());

        car1.accelerate();
        car1.accelerate(50);

        car2.accelerate();
        car2.accelerate(30);

        System.out.println("Total cars so far: " + Car.totalCars);

        Car.printTotalCars();

        // TASK 3

        Temperature temperature = new Temperature();
        System.out.println("Temperature:");
        System.out.println("Celsius: " + temperature.getCelsius());
        System.out.println("Fahrenheit: " + temperature.getFahrenheit());
        System.out.println();


        // TASK 4

        Vector<Student> students = new Vector<>();

        students.add(new Student("Student A", 1));
        students.add(new Student("Student B", 1));
        students.add(new Student("Student C", 1));
        students.add(new Student("Student D", 1));
        students.add(new Student("Student E", 1));


        Map<Student, Integer> gbd = new HashMap<>();

        System.out.print("Please, input grades for students:\n\n");
        Scanner sc = new Scanner(System.in);
        for (Student student : students) {
            System.out.print(student.getName() + ": ");
            int grade = sc.nextInt();
            gbd.put(student, grade);
        }

        sc.close();

        Course course = new Course("OOP", "desc", 4, new Vector<>());

        GradeBook gb = new GradeBook(course, gbd);

        gb.displayGradeReport();


        // TASK 5

        DragonLunch dragonLunch = new DragonLunch();

        Person person1 = new Person(Gender.BOY);
        Person person2 = new Person(Gender.GIRL);
        Person person3 = new Person(Gender.BOY);
        Person person4 = new Person(Gender.GIRL);

        dragonLunch.kidnap(person1);
        dragonLunch.kidnap(person2);
        dragonLunch.kidnap(person3);
        dragonLunch.kidnap(person4);

        System.out.println(dragonLunch.willDragonEatOrNot() ? "Yes" : "No");
    }
}
