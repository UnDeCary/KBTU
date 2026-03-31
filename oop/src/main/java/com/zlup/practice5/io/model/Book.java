package com.zlup.practice5.io.model;

import java.io.Serializable;

public class Book implements Serializable {
    private String title;
    private String author;
    private transient int visitCount;

    public Book(String title, String author) {
        this.title = title;
        this.author = author;
        this.visitCount = 0;
    }

    @Override
    public String toString() {
        return "Book [title=" + title + ", author=" + author + ", visitCount=" + visitCount + "]";
    }
}
