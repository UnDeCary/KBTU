#include <iostream>
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
    vector<char> list;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        list.push_back(s[i]);
    }

    quickSort(list, 0, list.size()-1);

    for (int i = 0; i < list.size(); i++) {
        cout << list[i];
    }

    return 0;
}