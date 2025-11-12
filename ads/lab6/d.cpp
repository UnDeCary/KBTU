#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Date {
    int y, m, d;
    string s;
};

int partition(vector<Date>& arr, int low, int high) {

    Date pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].y < pivot.y) {
            i++;
            swap(arr[i], arr[j]);
        }
        else if (arr[j].y == pivot.y) {
            if (arr[j].m < pivot.m) {
                i++;
                swap(arr[i], arr[j]);
            }
            else if (arr[j].m == pivot.m) {
                if (arr[j].d < pivot.d) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(vector<Date>& arr, int low, int high) {
  
    if (low < high) {
      
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    int n;

    cin >> n;
    vector<Date> dates(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dates[i].d = stoi(s.substr(0, 2));
        dates[i].m = stoi(s.substr(3, 2));
        dates[i].y = stoi(s.substr(6, 4));
        dates[i].s = s;
    }

    quickSort(dates, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << dates[i].s << endl;
    }

    return 0;
}