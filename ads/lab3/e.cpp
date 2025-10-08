#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int x1, y1, x2, y2;
    int low = 0, high = INT_MIN;

    vector<int> x, y;

    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        high = max(high, max(x2, y2));
        x.push_back(x2);
        y.push_back(y2);
    }

    while (low <= high) {
        int middle = floor((high+low)/2);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (x[i] <= middle && y[i] <= middle) {
                sum++;
            }
        }
        if (sum >= k) {
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }
    cout << low;

    return 0;
}