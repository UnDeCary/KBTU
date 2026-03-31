package com.zlup.practice4.problem2;

public class Student extends Person implements CanHavePizza, CanHaveRetake, Movable {

    @Override
    public void eatPizza() {
        System.out.println("*eating*");
    }

    @Override
    public void retakeExam() {
        System.out.println("It`s retake bro. -9999 aura");
    }

    @Override
    public void move() {
        System.out.println("*moving*");
    }
}
