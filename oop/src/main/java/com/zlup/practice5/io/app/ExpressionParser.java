package com.zlup.practice5.io.app;

import java.io.*;
import java.util.*;

public class ExpressionParser {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(new File("expressions.txt"));
            PrintWriter resWriter = new PrintWriter(new FileWriter("results.txt"));
            PrintWriter logWriter = new PrintWriter(new FileWriter("log.txt"))) {


            while (sc.hasNextLine()) {
                String line = sc.nextLine();
                try {
                    StringTokenizer st = new StringTokenizer(line, "+-*/", true);
                    if (st.countTokens() < 3) throw new NoSuchElementException("Missing operand");

                    double op1 = Double.parseDouble(st.nextToken().trim());
                    String op = st.nextToken();
                    double op2 = Double.parseDouble(st.nextToken().trim());

                    double result = switch (op) {
                        case "+" -> op1 + op2;
                        case "-" -> op1 - op2;
                        case "*" -> op1 * op2;
                        case "/" -> op1 / op2;
                        default -> throw new UnsupportedOperationException(op);
                    };
                    resWriter.println(line + " = " + result);
                } catch (Exception e) { logWriter.println("Error in [" + line + "]"); }
            }
        } catch (IOException e) {
            e.printStackTrace();
        };
    }
}
