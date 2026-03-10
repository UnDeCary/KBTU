package com.zlup.lab2.task1;

public class Cylinder extends Shape3D {
    private double radius, height;

    public Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    @Override
    public double volume() {
        return radius * radius * height;
    }

    @Override
    public double surfaceArea() {
        return (radius * radius * height) + Math.pow(3.14 * radius, 2);
    }
}
