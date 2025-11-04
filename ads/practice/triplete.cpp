#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> arr;
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        freq[val]++;
    }


    for (auto it : freq) {
        arr.push_back(it.first);
    }
    int s = arr.size();

    if (freq[0] >= 3) {
        cout << "0 0 0" << endl;
    }

    for (int i = 0; i < s-1; i++) {
        for (int j = i+1; j < s; j++) {
            int sum = -(arr[i] + arr[j]);

            if ((sum == arr[i] || sum == arr[j]) && freq[sum] >= 2) {
                cout << arr[i] << " " << arr[j] << " " << sum << endl;
            }
            else if ((sum != arr[i] && sum != arr[j]) && freq[sum] >= 1) {
                cout << arr[i] << " " << arr[j] << " " << sum << endl;
            }
        }
    }
     
    return 0;
}