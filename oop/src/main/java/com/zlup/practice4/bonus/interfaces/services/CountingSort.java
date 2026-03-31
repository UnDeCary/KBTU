package com.zlup.practice4.bonus.interfaces.services;

import com.zlup.practice4.bonus.interfaces.model.SortAlgorithm;

public class CountingSort implements SortAlgorithm {
    @Override
    public int[] sort(int[] array) {
        int[] count = new int[11];

        for (int num : array) {
            count[num]++;
        }

        int[] sorted = new int[array.length];
        int index = 0;

        for (int i = 0; i < count.length; i++) {
            while (count[i] > 0) {
                sorted[index++] = i;
                count[i]--;
            }
        }

        return sorted;
    }
}
