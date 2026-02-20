package com.zlup.lab1.task5;

public class Person {
    public final Gender gender;

    public Person(Gender gender) {
        this.gender = gender;
    }

    @Override
    public String toString() {
        return gender == Gender.BOY ? "Boy" : "Girl";
    }
}
