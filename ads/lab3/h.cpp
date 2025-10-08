#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> sums;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        s += val;
        sums.push_back(s);
    }

    auto get = [&](int val) {
        int l = 0;
        int r = sums.size() - 1;

        while (l <= r) {
            int mid = floor(l + (r-l)/2);

            if (sums[mid] < val) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return l + 1;
    };

    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        cout << get(val) << endl;
    }

    return 0;
}