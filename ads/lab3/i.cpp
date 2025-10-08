#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int l = 0, n, r, target;
    cin >> n;
    r = n-1;
    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    cin >> target;

    while (l <= r) {
        int mid = l + (r-l)/2;

        if (arr[mid] > target) {
            r = mid-1;
        }
        else if (arr[mid] < target) {
            l = mid+1;
        }
        else {
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;

    return 0;
}