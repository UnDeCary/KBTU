package com.zlup.practice4.problem2;

public class Main {
    public static void main(String[] args) {
        Cat cat = new Cat();
        Student student = new Student();
        Restaurant restaurant = new Restaurant();

        restaurant.servePizza(cat);
        restaurant.servePizza(student);
    }
}
