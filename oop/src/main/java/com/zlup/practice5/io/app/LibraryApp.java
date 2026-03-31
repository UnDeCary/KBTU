package com.zlup.practice5.io.app;

import com.zlup.practice5.io.model.Book;
import java.io.*;
import java.util.*;

public class LibraryApp {
    private static final String FILE_NAME = "library.dat";

    public static void main(String[] args) {
        List<Book> library = loadLibrary();
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.print("(A)dd, (L)ist, (Q)uit:");
            String choice = sc.nextLine().toUpperCase();

            if (choice.equals("A")) {
                System.out.print("Enter title: ");
                String t = sc.nextLine();
                System.out.print("Enter author: ");
                String a = sc.nextLine();
                library.add(new Book(t, a));
            }
            else if (choice.equals("L")) {
                library.forEach(System.out::println);
            }
            else if (choice.equals("Q")) {
                saveLibrary(library);
                break;
            }
        }
    }


    private static List<Book> loadLibrary() {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(FILE_NAME))) {
            return (ArrayList<Book>) ois.readObject();
        } catch (Exception e) { return new ArrayList<>(); }
    }

    private static void saveLibrary(List<Book> library) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(FILE_NAME))) {
            oos.writeObject(library);
        } catch (IOException e) { e.printStackTrace(); }
    }
}
