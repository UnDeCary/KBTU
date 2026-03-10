package com.zlup.lab2.task1;

import java.awt.*;

public class Cube extends Shape3D {
    private double side;

    public Cube(double side) {
        this.side = side;
    }

    @Override
    public double volume() {
        return side * side * side;
    }

    @Override
    public double surfaceArea() {
        return side * side * 6;
    }
}
