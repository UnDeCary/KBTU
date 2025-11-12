#include <iostream>
#include <vector>
#include <climits>

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
    vector<pair<int, int>> res;
    vector<int> v;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v.push_back(val);
    }

    quickSort(v, 0, n-1);

    int min_dif = INT_MAX;

    for (int i = 0; i < n-1; i++) {
        int dif = abs(v[i] - v[i+1]);
        if (dif < min_dif) {
            min_dif = dif;
            res.clear();
        }
        else if (dif > min_dif) {
            continue;
        }
        pair<int, int> p;
        p.first = v[i];
        p.second = v[i+1];
        res.push_back(p);
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << " " << res[i].second << " ";
    }
    cout << endl;

    return 0;
}