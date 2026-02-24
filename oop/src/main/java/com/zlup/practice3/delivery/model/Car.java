package com.zlup.practice3.delivery.model;

public class Car extends Vehicle {
    private int numerOfSeats;

    public Car(String model, int baseCost, Engine engine, int numberOfSeats) {
        super(model, baseCost, engine);
        this.numerOfSeats = numberOfSeats;
    }

    @Override
    public double calculateDeliveryCost() {
        return this.baseCost;
    }

    public double calculateDeliveryCost(double extraWeight) {
        return this.baseCost + extraWeight * 4;
    }
}
