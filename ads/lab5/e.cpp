#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr;

void swap(int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void heapify(int i) {
    int min = i, l = 2*i + 1, r = 2*i + 2;

    if (l < arr.size() && arr[l] < arr[min]) {
        min = l;
    }
    if (r < arr.size() && arr[r] < arr[min]) {
        min = r;
    }

    if (min != i) {
        swap(i, min);
        heapify(min);
    }
    
}

void heapifyUp(int i) {
    if (i <= 0) {
        return;
    }
    
    int parent = (i-1) / 2;

    if (arr[i] < arr[parent]) {
        swap(i, parent);
        heapifyUp(parent);
    }
}

int main() {
    int q, k;
    cin >> q >> k;
    long long sum = 0;

    for (int i = 0; i < q; i++) {
        string op;
        cin >> op;
        if (op == "print") {
            cout << sum << endl;
        }

        else if (op == "insert") {
            int val;
            cin >> val;

            arr.push_back(val);
            heapifyUp(arr.size()-1);
            sum += val;

            if (arr.size() > k) {
                int a = arr[0];
                swap(0, arr.size()-1);
                arr.pop_back();
                heapify(0);

                sum -= a;
            }
        }
    }

    return 0;
}