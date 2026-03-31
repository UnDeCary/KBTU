package com.zlup.practice5.io.app;

import java.io.*;
import java.util.*;

public class WordFrequencyCounter {
    public static void main(String[] args) {
        Map<String, Integer> counts = new HashMap<>();

        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"))) {
            String line;

            while ((line = reader.readLine()) != null) {
                String[] words = line.toLowerCase().replaceAll("[^a-zA-Zа-яА-я]", " ").split("\\s+");

                for (String word : words) {
                    if (!word.isEmpty()) {
                        counts.put(word, counts.getOrDefault(word, 0) + 1);
                    }
                }
            }
        } catch (IOException e) {
            System.err.println("Error while reading input file.");
        }

        List<Map.Entry<String, Integer>> list = new ArrayList<>(counts.entrySet());
        list.sort((a, b) -> b.getValue().compareTo(a.getValue()));

        try (PrintWriter writer = new PrintWriter(new FileWriter("report.txt"))) {
            for (Map.Entry<String, Integer> entry : list) {
                writer.println(entry.getKey() + "\t" + entry.getValue());
            }
        }
        catch (IOException e) {
            System.err.println("Error while writing to report.txt.");
        }
    }
}
