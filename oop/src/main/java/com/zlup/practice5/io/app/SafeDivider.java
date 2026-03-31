package com.zlup.practice5.io.app;

import java.util.InputMismatchException;
import java.util.Scanner;

public class SafeDivider {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while (true) {
            try {
                System.out.print("Enter first integer: ");
                String input1 = scan.nextLine();
                int x1 = Integer.parseInt(input1);
                if (x1 == 0) break;

                System.out.print("Enter second integer: ");
                String input2 = scan.nextLine();
                int x2 = Integer.parseInt(input2);

                int result = x1 / x2;
                System.out.println("Result: " + result);
            }
            catch (ArithmeticException e) {
                System.err.println("Error: Division by zero");
            }
            catch (InputMismatchException e) {
                System.err.println("Error: Non valid integers.");
            }
        }

        scan.close();
    }
}
