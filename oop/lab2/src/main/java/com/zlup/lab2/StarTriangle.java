package com.zlup.lab2;

public class StarTriangle {
    int width;

    public StarTriangle(int width) {
        this.width = width;
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();

        for (int i = 1; i <= this.width; i++) {
            result.append("[*]".repeat(i)).append("\n");
        }

        return result.toString();
    }
}
