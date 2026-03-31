package com.zlup.lab2.task5;

public class PhDStudent extends Student {

    private String research;
    private String major;

    public PhDStudent(String name, int age, String major, String research) {
        super(name, age, major);
        this.research = research;
    }

    @Override
    public void assignPet(Animal pet) {
        if (pet instanceof Dog) {
            System.out.println("PhD students cannot have dogs!");
            return;
        }

        super.assignPet(pet);
    }

    public String getOccupation() {
        return "Research: " + research + "\nMajor: " + major;
    }

}
