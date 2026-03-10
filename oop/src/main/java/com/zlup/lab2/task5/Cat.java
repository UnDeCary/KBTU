package com.zlup.lab2.task5;

public class Cat extends Animal {

    public Cat(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void makeSound() {
        System.out.println("Meow!");
    }
}
