package com.zlup.lab3.problem6;

public class Main {
    public static void main(String[] args) {
        AnimalAdvance animal = new AnimalAdvance("Bobik", 4);

        PersonAdvanced person = new PersonAdvanced("Bob", 20);

        animal.makeSound();
        person.move();
    }
}
