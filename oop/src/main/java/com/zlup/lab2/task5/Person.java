package com.zlup.lab2.task5;

import java.util.Objects;

public abstract class Person {
    protected String name;
    protected int age;
    protected Animal pet;

    public void assignPet(Animal pet) {
        this.pet = pet;
    }

    public void removePet() {
        this.pet = null;
    }

    public boolean hasPet() {
        return this.pet != null;
    }

    public void leavePetWith(Person person) {
        if (!hasPet()) {
            System.out.println(name + " has no pet.");
            return;
        }

        if (person.hasPet()) {
            System.out.println(person.name + " already has a pet.");
            return;
        }

        person.assignPet(pet);
        removePet();
    }

    public void retrievePetFrom(Person person) {
        if (!person.hasPet()) {
            System.out.println(person.name + " has no pet.");
            return;
        }

        if (hasPet()) {
            System.out.println(name + " already has a pet.");
            return;
        }

        assignPet(person.pet);
        person.removePet();
    }

    public abstract String getOccupation();

    @Override
    public String toString() {
        return this.name + " (" + this.age + ") \n" + (pet == null ? "no pet" : pet.getName());
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || !(o instanceof Person)) return false;
        Person p = (Person) o;
        return this.name == p.name;
    }

    @Override
    public int hashCode() {
        return Objects.hash(this.age, this.name, this.pet);
    }


}
