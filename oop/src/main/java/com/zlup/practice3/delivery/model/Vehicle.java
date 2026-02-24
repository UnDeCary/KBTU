package com.zlup.practice3.delivery.model;

public abstract class Vehicle {
    public String model;
    public double baseCost;
    public Engine engine;

    public Vehicle(String model, double baseCost, Engine engine) {
        this.model = model;
        this.baseCost = baseCost;
        this.engine = engine;
    }

    public double calculateDeliveryCost() {
        return this.baseCost + engine.horsepower * 10;
    }

    public String getVehicleInfo() {
        StringBuilder sb = new StringBuilder();
        sb.append("--- " + this.model + " ---\n");
        sb.append("Base cost: " + this.baseCost);
        return sb.toString();
    }

}
