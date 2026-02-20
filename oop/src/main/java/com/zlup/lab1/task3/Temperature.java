package com.zlup.lab1.task3;

public class Temperature {
    private double temperature;
    private char type;

    public Temperature() {
        this.temperature = 0;
        this.type = 'C';
    }

    public Temperature(double temperature) {
        this.temperature = temperature;
        this.type = 'C';
    }

    public Temperature(char type) {
        this.temperature = 0;
        this.type = type;
    }

    public Temperature(double temperature, char type) {
        this.temperature = temperature;
        this.type = type;
    }

    public double getCelsius() {
        if (type == 'C') {
            return temperature;
        }
        else {
            return 5 * (temperature - 32) / 9;
        }
    }

    public double getFahrenheit() {
        if (type == 'F') {
            return temperature;
        }
        else {
            return (9 * (temperature / 5)) + 32;
        }
    }

    public void setTemperature(double value) {
        this.temperature = value;
    }

    public void setType(char type) {
        if (this.type != type && type == 'F') {
            this.temperature = this.getFahrenheit();
        }
        else if (this.type != type && type == 'C') {
            this.temperature = this.getCelsius();
        }
        this.type = type;
    }

    public void setScale(double value, char type) {
        this.temperature = value;
        this.type = type;
    }
}
