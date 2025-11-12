#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

int partition(vector<pair<string, double>>& arr, int low, int high) {

    pair pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].second < pivot.second) {
            i++;
            swap(arr[i], arr[j]);
        }
        else if (arr[j].second - pivot.second < 1e-9) {
            if (arr[j].first < pivot.first) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
    }

    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(vector<pair<string, double>>& arr, int low, int high) {
  
    if (low < high) {
      
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    int n;
    cin >> n;

    vector<pair<string, double>> gpa_table;

    map<string, double> grade_table = {
        {"A+", 4.00},
        {"A", 3.75},
        {"B+", 3.50},
        {"B", 3.00},
        {"C+", 2.50},
        {"C", 2.00},
        {"D+", 1.50},
        {"D", 1.00},
        {"F", 0.00}
    };

    for (int i = 0; i < n; i++) {
        string last_name, first_name, full_name;
        cin >> last_name >> first_name;

        full_name = last_name + " " + first_name;
        int z;
        double sum = 0, sum_cred = 0;
        cin >> z;
        for (int j = 0; j < z; j++) {
            string grade;
            int l;
            cin >> grade >> l;
            sum += grade_table[grade] * l;
            sum_cred += l;
        }
        
        gpa_table.push_back( { full_name, round(((sum/sum_cred) * 1000.0L)/1000.0L) } );
    }

    quickSort(gpa_table, 0, n-1);

    cout << fixed << setprecision(3);
    for (auto item : gpa_table) {
        cout  << item.first << " " << item.second << endl;
    }



    return 0;
}