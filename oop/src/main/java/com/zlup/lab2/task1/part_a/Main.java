package com.zlup.lab2.task1.part_a;

public class Main {
    public static void main(String[] args) {
        Cube cb = new Cube(4.0);
        Sphere sp = new Sphere(3.0);
        Cylinder cl = new Cylinder(2.5, 3.0);

        System.out.println("The volume of cube is " + cb.volume());
        System.out.println("The surface area of cube is " + cb.surfaceArea());

        System.out.println("The volume of sphere is " + sp.volume());
        System.out.println("The surface area of sphere is " + sp.surfaceArea());

        System.out.println("The volume of cylinder is " + cl.volume());
        System.out.println("The surface area of cylinder is " + cl.surfaceArea());
    }
}
