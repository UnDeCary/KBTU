package com.zlup.practice3.delivery.model;

public class Truck extends Vehicle{
    private int maxLoad;

    public Truck(String model, int baseCost, Engine engine, int maxLoad) {
        super(model, baseCost, engine);
        this.maxLoad = maxLoad;
    }

    @Override
    public double calculateDeliveryCost() {
        return this.baseCost;
    }

    public double calculateDeliveryCost(double distance, double fuelPrice) {
        return this.baseCost + distance * fuelPrice;
    }
}
