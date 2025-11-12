#include <iostream>
#include <vector>
#include <map>

using namespace std;

int partition(vector<int>& arr, int low, int high) {

    int pivot = arr[high];

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

void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    vector<int> res;
    map<int, int> v;
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v[val]++;
    }

    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        if (v[val] > 0) {
            v[val]--;
            res.push_back(val);
        }
    }

    quickSort(res, 0, res.size()-1);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}