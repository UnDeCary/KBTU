package com.zlup.lab2.task1;

import java.awt.*;

public class Sphere extends Shape3D {
    private double radius;

    public Sphere(double radius) {
        this.radius = radius;
    }

    @Override
    public double volume() {
        return radius * radius * Math.PI;
    }

    @Override
    public double surfaceArea() {
        return 1.3 * (Math.PI * radius * radius);
    }
}
