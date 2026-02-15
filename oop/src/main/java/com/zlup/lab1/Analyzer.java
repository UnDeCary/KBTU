package com.zlup.lab1;

import java.util.Scanner;

public class Analyzer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Data data = new Data();

        while (true) {
            System.out.print("Enter number (Q to quit): ");
            String input = scanner.nextLine();

            if (input.equalsIgnoreCase("Q")) {
                System.out.println("Average: " + data.getAverage());
                System.out.println("Maximum: " + data.getMax());
                break;
            }

            try {
                int value = Integer.parseInt(input);
                data.add(value);
            }  catch (NumberFormatException e) {
                System.out.println("Invalid input. Enter an integer or Q.");
            }
        }

        scanner.close();
    }
}
