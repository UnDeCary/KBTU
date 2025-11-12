#include <iostream>
#include <vector>

using namespace std;

bool compareRows(const vector<int>& a, const vector<int>& b) {
    int sumA = 0, sumB = 0;
    for (int x : a) sumA += x;
    for (int x : b) sumB += x;

    if (sumA != sumB)
        return sumA > sumB;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            return a[i] < b[i];
    }

    return false;
}

int partition(vector<vector<int>>& arr, int low, int high) {
    vector<int> pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (compareRows(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<vector<int>>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> rows(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rows[i][j];
        }
    }

    quickSort(rows, 0, n - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << rows[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}