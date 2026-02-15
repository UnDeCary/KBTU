package com.zlup.lab1;

public class Main {
    public static void main(String[] args) {
        Car car1 = new Car("VIN123", "Porsche 911 GT3RS", EngineType.ELECTIC);
        Car car2 = new Car("VIN456", "Ford Mustang", EngineType.PETROL);

        System.out.println(car1.getModel() + " has VIN " + car1.getVin() + " and engine " + car1.getEngineType());

        car1.accelerate();
        car1.accelerate(50);

        car2.accelerate();
        car2.accelerate(30);

        System.out.println("Total cars so far: " + Car.totalCars);

        Car.printTotalCars();
    }
}
