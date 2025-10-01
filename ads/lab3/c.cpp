#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

int main() {
    int n, q, max_val = INT_MIN;
    cin >> n >> q;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (max_val < nums[i]) {
            max_val = nums[i];
        }
    }

    unordered_map<int, int> freq, pref;

    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    pref[0] = freq[0];
    for (int i = 1; i <= max_val; i++) {
        pref[i] = pref[i-1] + freq[i];
    }

    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int count1 = pref[r1] - pref[l1-1];
        int count2 = pref[r2] - pref[l2-1];
        int intersection = 0;
        if (!(r1 < l2 || r2 < l1)) {
            int left = max(l1, l2);
            int right = min(r1, r2);

            intersection = pref[right] - pref[left-1];
        }

        cout << count1 + count2 - intersection << endl;
    }

    return 0;
}