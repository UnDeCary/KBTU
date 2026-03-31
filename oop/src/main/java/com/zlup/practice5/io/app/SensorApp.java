package com.zlup.practice5.io.app;

import java.io.*;

public class SensorApp {
    public static void main(String[] args) throws IOException {
        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream("sensor.bin"))) {
            for (int i = 0; i < 60; i++) dos.writeDouble(20.0 + i * 0.1);
        }

        try (RandomAccessFile raf = new RandomAccessFile("sensor.bin", "rw")) {
            raf.seek(29 * 8);
            raf.writeDouble(999.9);
        }

        double sum = 0, max = -1;

        try (DataInputStream dis = new DataInputStream(new FileInputStream("sensor.bin"))) {
            for (int i = 0; i < 60; i++) {
                double val = dis.readDouble();
                sum += val;
                if (val > max) max = val;
            }
        }
        System.out.println("Average: " + (sum / 60));
        System.out.println("Max: " + max);
    }
}
