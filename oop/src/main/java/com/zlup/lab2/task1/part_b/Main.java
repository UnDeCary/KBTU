package com.zlup.lab2.task1.part_b;

public class Main {
    public static void main(String[] args) {
        Book book = new Book("CISCO CCNA", "имеется", 1900, 100000);

        System.out.println("Number of pages: " + book.getNumberOfPages());
        book.setNumberOfPages(20000);

        System.out.println(book);
    }
}
