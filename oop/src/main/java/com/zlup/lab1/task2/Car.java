package com.zlup.lab1.task2;

public class Car {

    public static final int MAX_SPEED = 300;
    public static int totalCars = 0;

    private final String vin;
    private final String model;
    private final EngineType engineType;

    private int currentSpeed;

    {
        currentSpeed = 0;
        totalCars++;
        System.out.println("New car created! Total cars: " + totalCars);
    }

    public Car(String vin, String model, EngineType engineType) {
        this.vin = vin;
        this.model = model;
        this.engineType = engineType;
    }

    public void accelerate() {
        if (currentSpeed + 10 <= MAX_SPEED) {
            currentSpeed += 10;
            System.out.println(model + " accelerated to " + currentSpeed + " km/h");
        }
    }

    public void accelerate(int value) {
        if (currentSpeed + value <= MAX_SPEED) {
            currentSpeed += value;
            System.out.println(model + " accelerated to " + currentSpeed + " km/h");
        }
    }

    public String getVin() {
        return vin;
    }

    public String getModel() {
        return model;
    }

    public EngineType getEngineType() {
        return engineType;
    }

    public int getCurrentSpeed() {
        return currentSpeed;
    }

    public void setCurrentSpeed(int speed) {
        this.currentSpeed = speed;
    }


    public static void printTotalCars() {
        System.out.println("Total cars: " + totalCars);
    }
}
