#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;


int main() {
    int n, val, max = INT_MIN, min = 1, ans = 0;
    long long f;
    cin >> n >> f;
    vector<int> nums;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
        if (val > max) {
            max = val;
        }
    }

    while (min <= max) {
        int mid = floor(min + (max - min)/2);
        int sum = 0;

        for (auto val : nums) {
            sum += (val + mid - 1) / mid;
        }

        if (sum <= f) {
            max = mid - 1;
            ans = mid;
        }
        else if (sum > f) {
            min = mid + 1;
        }
        else break;
    }

    cout << ans << endl;


    return 0;
}