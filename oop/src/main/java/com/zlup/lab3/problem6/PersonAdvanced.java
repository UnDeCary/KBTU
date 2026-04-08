package com.zlup.lab3.problem6;

import com.zlup.lab2.task5.Person;

public class PersonAdvanced extends Person implements Comparable<PersonAdvanced>, Movable {
    public PersonAdvanced(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public int compareTo(PersonAdvanced o) {
        return this.name.compareTo(o.name);
    }

    @Override
    public void move() {
        System.out.println("Moving!");
    }

    @Override
    public String getOccupation() {
        return "";
    }
}
