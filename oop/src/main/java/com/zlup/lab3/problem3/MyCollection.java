package com.zlup.lab3.problem3;

public interface MyCollection<T> {
    void add(T element);
    void remove(T element);
    int size();
    boolean contains(T element);
    boolean isEmpty();
    void clear();
}
