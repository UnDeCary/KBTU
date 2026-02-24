package com.zlup.practice3.animal.model;

public class Animal {
    private final String name;
    private int age;

    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void makeSound() {
        System.out.println("Meow!");
    }

    public void eat() {
        System.out.println(this.name + " ate something!");
    }

    public void eat(String food) {
        System.out.println(this.name + " ate " + food);
    }

    public void getInfo() {
        System.out.println("Name: " + this.name + "\nAge: " + this.age);
    }
}
