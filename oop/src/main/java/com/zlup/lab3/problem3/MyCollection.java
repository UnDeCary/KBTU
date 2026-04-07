package com.zlup.lab3.problem3;

public interface MyCollection<E> {
    void add(E element);
    void remove(E element);
    int size();
    boolean contains(E element);
    boolean isEmpty();
    void clear();
}
