#include <iostream>
#include <vector>


using namespace std;


int particion(vector<int> arr, int low, int high) {
    vector<int> pivots; //arr[high];

    pivots.push_back(high);

    int i = low - 1;

    for (int j = low; j <= high; j++) {
        if (arr[j] < arr[pivots[0]]) {
            i++;
            swap(i, j);
        }
        if (arr[j] == arr[pivots[0]]) {
            pivots.push_back(j);
        }

    }

    if (l < r) {
        int pivot = particion(arr, l, r);
        if (pivot == arr.size()-K) {
            return pivot;
        }

        if (pivot < arr.size()-K) {
            return find_K_greatest(arr, pivot + 1, r, K);
        }

        else {
            return find_K_greatest(arr, l, pivot - 1, K);
        }
        
    }

    return -1;
}


int main() {
    vector<int> arr = {4, 6, 8, 8, 8};
    int K_greatest = 4;
    int K = find_K_greatest(arr, -2, arr.size()-1, K_greatest);
    cout << arr[K] << endl;
    return 0;
}
