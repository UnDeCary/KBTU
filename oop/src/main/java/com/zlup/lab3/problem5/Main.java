package com.zlup.lab3.problem5;

import java.util.Collections;
import java.util.Vector;
import com.zlup.practice2.Time;

public class Main {
    public static void main(String[] args) {

        Vector<Chocolate> chocolates = new Vector<>();

        chocolates.add(new Chocolate(252, "Twix"));
        chocolates.add(new Chocolate(350, "Snickers"));
        chocolates.add(new Chocolate(240, "Snatch"));
        Sort.bubbleSort(chocolates.toArray(new Chocolate[0]));
        Collections.sort(chocolates);
        System.out.println(chocolates);

        Vector<Time> times = new Vector<>();
        times.add(new Time(15, 23, 24));
        times.add(new Time(21, 43, 23));
        times.add(new Time(5, 31, 43));
        Sort.bubbleSort(times.toArray(new Time[0]));
        Collections.sort(times);
        System.out.println(times);


    }
}
