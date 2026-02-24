package com.zlup.practice3.animal.model;

public class Dog extends Animal {
    private final String breed;

    public Dog(String name, int age, String breed) {
        super(name, age);
        this.breed = breed;
    }

    @Override
    public void makeSound() {
        System.out.println("Wouf!");
    }

    @Override
    public void getInfo() {
        super.getInfo();
        System.out.println("Breed: " + this.breed);
    }
}
