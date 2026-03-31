package com.zlup.practice4.bonus.interfaces.main;

import com.zlup.practice4.bonus.interfaces.model.SortAlgorithm;
import com.zlup.practice4.bonus.interfaces.services.CountingSort;

public class Main {

    public static void main(String[] args) {
        int[] array = new int[]{5, 3, 1, 7, 3, 0, 10, 2, 5, 1};

        SortAlgorithm sortAlgorithm = new CountingSort();

        int[] sorted = sortAlgorithm.sort(array);

        for (int num : sorted) {
            System.out.print(num + " ");
        }

    }
}
