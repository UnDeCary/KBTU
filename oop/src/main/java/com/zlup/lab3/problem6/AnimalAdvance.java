package com.zlup.lab3.problem6;

import com.zlup.lab2.task5.Animal;

public class AnimalAdvance extends Animal implements Comparable<AnimalAdvance>, CanSound {
    public AnimalAdvance(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public void makeSound() {
        System.out.println("sound");
    }

    @Override
    public int compareTo(AnimalAdvance o) {
        return this.getName().compareTo(o.getName());
    }
}
