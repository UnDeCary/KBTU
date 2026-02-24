package com.zlup.practice3.delivery.service;

import com.zlup.practice3.delivery.model.Vehicle;

import java.util.List;

public class DeliveryService {

    public final void printAllVehicles(List<Vehicle> vehicles) {
        vehicles.forEach(vehicle -> {
            System.out.println(vehicle.getVehicleInfo());
        });
    }

    public final void calculateAllDeliveries(List<Vehicle> vehicles) {
        vehicles.forEach(vehicle -> {
            System.out.println(vehicle.calculateDeliveryCost());
        });
    }

    public final void calculateTotalCost(List<Vehicle> vehicles) {
        double sum = 0;
        for (Vehicle vehicle : vehicles) {
            sum += vehicle.calculateDeliveryCost();
        }
        System.out.println(sum);
    }
}
