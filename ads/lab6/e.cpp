#include <iostream>
#include <vector>

using namespace std;


int partition(vector<vector<int>>& arr, int low, int high, int col) {

    int pivot = arr[high][col];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j][col] < pivot) {
            i++;
            swap(arr[i][col], arr[j][col]);
        }
    }

    swap(arr[i + 1][col], arr[high][col]);  
    return i + 1;
}

void quickSort(vector<vector<int>>& arr, int low, int high, int col) {
  
    if (low < high) {
      
        int pi = partition(arr, low, high, col);

        quickSort(arr, low, pi - 1, col);
        quickSort(arr, pi + 1, high, col);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }



    for (int i = 0; i < m; i++) {
        quickSort(matrix, 0, n-1, i);
    }

    
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}