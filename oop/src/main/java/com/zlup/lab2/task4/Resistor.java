package com.zlup.lab2.task4;

public class Resistor extends Circuit{
    private double resistance;
    private double potentialDiff;

    public Resistor(double resistance) {
        this.resistance = resistance;
        potentialDiff = 0;
    }

    public double getResistance() {
        return resistance;
    }

    public double getPotentialDiff() {
        return potentialDiff;
    }

    public void applyPotentialDiff(double V) {
        potentialDiff = V;
    }
}
