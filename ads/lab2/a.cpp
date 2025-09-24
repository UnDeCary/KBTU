#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, k, a, min = INT_MAX;
    vector<int> nums;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        nums.push_back(a);
    }

    cin >> k;

    for (int i = 0; i < n; i++) {
        if (abs(k - nums[i]) < min) {
            min = abs(k - nums[i]);
            a = i;
        }
    }

    cout << a;

    return 0;
}