package com.zlup.lab2.task5;

public abstract class Animal {
    protected String name;
    protected int age;


    public abstract void makeSound();

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}
