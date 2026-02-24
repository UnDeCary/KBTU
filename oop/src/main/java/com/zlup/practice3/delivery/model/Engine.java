package com.zlup.practice3.delivery.model;

public class Engine {
    public final String type;
    public final int horsepower;

    public Engine(String type, int horsepower) {
        this.type = type;
        this.horsepower = horsepower;
    }

    public void getEngineInfo() {
        System.out.println("--- Engine ---");
        System.out.println("Type: " + this.type);
        System.out.println("Horsepower: " + this.horsepower);

    }
}
