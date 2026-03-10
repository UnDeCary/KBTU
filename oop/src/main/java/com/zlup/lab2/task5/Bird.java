package com.zlup.lab2.task5;

public class Bird extends Animal {

    public Bird(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void makeSound() {
        System.out.println("Curlik!");
    }
}
