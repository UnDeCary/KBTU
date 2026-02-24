package com.zlup.practice3.animal.app;

import com.zlup.practice3.animal.model.*;

import java.util.ArrayList;
import java.util.List;

public class MainApp {
    public static void main(String[] args) {
        List<Animal> animals = new ArrayList<Animal>();

        animals.add(new Animal("Biba", 4));
        animals.add(new Animal("Boba", 3));
        animals.add(new Dog("Marshal", 3, "Akita-Niu"));

        animals.forEach((animal -> {
            animal.getInfo();
            animal.makeSound();
            animal.eat();
            animal.eat("Sandwich");
            System.out.println("-------------");
        }));
    };
}
