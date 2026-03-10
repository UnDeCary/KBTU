package com.zlup.lab2.task1;

public class Person {
    private String name;
    private int age;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null) return false;

        Person person = (Person) o;
        if (this.age == person.age) return true;
        return false;
    }

    @Override
    public int hashCode() {
        return age;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Name: " + getName() + "\n");
        sb.append("Age: " + getAge() + "\n");
        return sb.toString();
    }
}
