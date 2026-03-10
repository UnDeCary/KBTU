package com.zlup.lab2.task5;

public class Dog extends Animal {

    public Dog(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void makeSound() {
        System.out.println("Wouf!");
    }
}
