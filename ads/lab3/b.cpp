#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

int main() {
    int n, k;
    long long max_val = INT_MIN, sum = 0;
    cin >> n >> k;
    vector<int> houses(n);

    for (int i = 0; i < n; i++) {
        cin >> houses[i];
        if (houses[i] > max_val) {
            max_val = houses[i];
        }
        sum += houses[i];
    }

    long long left = max_val, right = sum;
    long long answer = sum;

    while (left <= right) {
        long long middle = floor(left + (right-left)/2);
        long long block_sum = 0;
        int roadblocks = 0;

        for (int i = 0; i < n; i++) {
            if (block_sum + houses[i] > middle) {
                block_sum = houses[i];
                roadblocks++;
            }
            else {
                block_sum += houses[i];
            }
        }
        if (roadblocks < k) {
            answer = middle;
            right = middle-1;
        }
        else {
            left = middle+1;
        }
    }

    cout << answer << endl;

    return 0;
}