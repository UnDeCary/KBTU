package com.zlup.lab1;

public class Data {
    private double sum;
    private double maximum;
    private int count;

    public Data() {
        count = 0;
        sum = 0;
    }

    public void add(int value) {
        sum += value;
        count++;

        if (count == 1 || maximum < value) {
            maximum = value;
        }
    }

    public double getAverage() {
        if (count == 0) {
            return 0;
        }
        return sum / count;
    }

    public double getMax() {
        return maximum;
    }
}
