package com.zlup.practice3.delivery.app;

import com.zlup.practice3.delivery.model.Car;
import com.zlup.practice3.delivery.model.Engine;
import com.zlup.practice3.delivery.model.Truck;
import com.zlup.practice3.delivery.model.Vehicle;
import com.zlup.practice3.delivery.service.DeliveryService;

import java.util.ArrayList;
import java.util.List;

public class MainApp {
    public static void main(String[] args) {
        List<Vehicle> vehicles = new ArrayList<>();

        vehicles.add(new Car("Tesla Model S", 2500, new Engine("Electrical", 200), 4));
        vehicles.add(new Car("Ford Mustang", 3000, new Engine("Petrol", 300), 2));
        vehicles.add(new Truck("Truck", 3500, new Engine("Disel", 250), 8));

        vehicles.get(0).engine.getEngineInfo();

        DeliveryService dS = new DeliveryService();
        dS.calculateTotalCost(vehicles);
        dS.calculateAllDeliveries(vehicles);
        dS.printAllVehicles(vehicles);
    }
}
