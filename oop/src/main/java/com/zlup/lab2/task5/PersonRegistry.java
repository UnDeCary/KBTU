package com.zlup.lab2.task5;

import java.util.ArrayList;

public class PersonRegistry {

    private ArrayList<Person> persons = new ArrayList<>();

    public void addPerson(Person person) {
        persons.add(person);
    }

    public void removePerson(Person person) {
        persons.remove(person);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        for (Person person : persons) {
            sb.append(person.toString()).append("\n");
        }

        return sb.toString();
    }
}
