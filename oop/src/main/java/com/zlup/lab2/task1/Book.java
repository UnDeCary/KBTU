package com.zlup.lab2.task1;

public class Book extends LibraryItem {
    private int numberOfPages;

    public Book(String title, String author, int publicationYear, int numberOfPages) {
        super(title, author, publicationYear);
        this.numberOfPages = numberOfPages;
    }

    public int getNumberOfPages() {
        return numberOfPages;
    }

    public void setNumberOfPages(int numberOfPages) {
        this.numberOfPages = numberOfPages;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("Title: " + getTitle() + "\n");
        builder.append("Author: " + getAuthor() + "\n");
        builder.append("Publication Year: " + getPublicationYear() + "\n");
        builder.append("Number of Pages: " + getNumberOfPages() + "\n");
        return builder.toString();
    }


}
