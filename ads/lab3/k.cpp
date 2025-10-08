#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<long long> pref(n+1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + nums[i-1];
    }

    auto lower_bound_custom = [&](long long val, int left) {
        int l = left, r = n;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (pref[mid] >= val) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    };

    int answer = INT_MAX;

    for (int i = 0; i < n; i++) {
        long long target = pref[i] + k;
        int j = lower_bound_custom(target, i+1);
        if (j != -1) {
            answer = min(answer, j - i);
        }
    }

    cout << answer << endl;

    return 0;
}
