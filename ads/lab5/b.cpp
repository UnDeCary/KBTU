#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void swap(int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void heapify(int i) {
    int max = i, l = 2*i + 1, r = 2*i + 2;

    if (l < arr.size() && arr[l] > arr[max]) {
        max = l;
    }
    if (r < arr.size() && arr[r] > arr[max]) {
        max = r;
    }

    if (max != i) {
        swap(i, max);
        heapify(max);
    }
    
}

void heapifyUp(int i) {
    if (i <= 0) {
        return;
    }
    
    int parent = (i-1) / 2;

    if (arr[i] > arr[parent]) {
        swap(i, parent);
        heapifyUp(parent);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(i);
    }

    while (arr.size() > 1) {
        int a = arr[0];
        swap(0, arr.size()-1);
        arr.pop_back();
        heapify(0);

        int b = arr[0];
        swap(0, arr.size()-1);
        arr.pop_back();
        heapify(0);

        if (a - b != 0) {
            arr.push_back(a - b);
            heapifyUp(arr.size()-1);
        }
    }

    if (arr.size() == 1) {
        cout << arr.front();
    }
    else {
        cout << 0;
    }
    return 0;
}