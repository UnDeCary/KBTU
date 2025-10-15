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

int main() {
    int n, x;
    long long sum = 0;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(i);
    }

    for (int i = 0; i < x; i++) {
        sum += arr.front();
        arr[0]--;
        heapify(0);
    }

    cout << sum;
    return 0;
}