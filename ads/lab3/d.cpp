#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <math.h>

using namespace std;

int main() {
    int n, q, max_val = INT_MIN;
    cin >> n >> q;
    vector<int> nums(n), keys;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (max_val < nums[i]) {
            max_val = nums[i];
        }
    }

    map<int, int> freq, pref;

    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    int sum = 0;
    for (auto [val, count] : freq) {
        sum += count;
        pref[val] = sum;
        keys.push_back(val);
    }

    auto get = [&](int val) {
        int left = 0;
        int right = keys.size() - 1;
        int last_val = -1;

        while (left <= right) {
            int middle = floor(left + (right-left)/2);

            if (keys[middle] < val) {
                last_val = keys[middle];
                left = middle+1;
            }
            else if (keys[middle] > val) {
                right = middle-1;
            }
            else {
                last_val = keys[middle];
                break;
            }
        }

        return last_val;
    };

    auto count = [&](int l, int r) {
        int left_val = get(l);
        int right_val = get(r);
        if (left_val == -1) {
            return pref[right_val];
        }
        return pref[get(r)] - pref[get(l-1)];
    };


    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int count1 = count(l1, r1);
        int count2 = count(l2, r2);
        int intersection = 0;
        if (!(r1 < l2 || r2 < l1)) {
            int left = max(l1, l2);
            int right = min(r1, r2);

            intersection = count(left, right);
        }

        cout << count1 + count2 - intersection << endl;
    }

    return 0;
}