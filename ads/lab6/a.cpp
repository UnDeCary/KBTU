#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int partition(vector<char>& arr, int low, int high) {

    char pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(vector<char>& arr, int low, int high) {
  
    if (low < high) {
      
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<char> vowels;
    vector<char> consonants;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (string("aeiou").find(c) != string::npos) {
            vowels.push_back(c);
        }
        else {
            consonants.push_back(c);
        }
    }

    quickSort(vowels, 0, vowels.size()-1);
    quickSort(consonants, 0, consonants.size()-1);

    for (char c : vowels) {
        cout << c;
    }
    for (char c : consonants) {
        cout << c;
    }

    return 0;
}