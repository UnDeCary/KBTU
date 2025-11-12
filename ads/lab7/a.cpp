#include <iostream>
#include <vector>
#include <string>

using namespace std;

int partition(vector<string>& arr, int low, int high, vector<int>& index) {
    int pivot = arr[high].size();
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].size() < pivot || 
            (arr[j].size() == pivot && index[j] < index[high])) {
            i++;
            swap(arr[i], arr[j]);
            swap(index[i], index[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    swap(index[i + 1], index[high]);
    return i + 1;
}

void quickSort(vector<string>& arr, int low, int high, vector<int>& index) {
    if (low < high) {
        int pi = partition(arr, low, high, index);
        quickSort(arr, low, pi - 1, index);
        quickSort(arr, pi + 1, high, index);
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        vector<string> words;
        vector<int> index;
        string current;
        int pos = 0;

        for (char c : line) {
            if (c == ' ') {
                if (!current.empty()) {
                    words.push_back(current);
                    index.push_back(pos++);
                    current.clear();
                }
            } else {
                current += c;
            }
        }

        if (!current.empty()) {
            words.push_back(current);
            index.push_back(pos);
        }

        if (!words.empty()) {
            quickSort(words, 0, words.size() - 1, index);
        }

        for (int j = 0; j < words.size(); j++) {
            cout << words[j] << " ";
        }
        cout << endl;
    }

    return 0;
}