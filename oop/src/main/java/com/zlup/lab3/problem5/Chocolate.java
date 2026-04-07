package com.zlup.lab3.problem5;

public class Chocolate implements Comparable<Chocolate> {
    double weight;
    String name;

    public Chocolate(double weight, String name) {
        this.weight = weight;
        this.name = name;
    }

    @Override
    public String toString() {
        return this.name + " " + this.weight + " g.";
    }

    @Override
    public int compareTo(Chocolate o) {
        return Double.compare(this.weight, o.weight);
    }


}
