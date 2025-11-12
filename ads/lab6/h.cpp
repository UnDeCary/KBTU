#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> list(n);

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    char letter;
    cin >> letter;

    int l = 0, r = n-1;
    char min = list[0];

    while (l <= r) {
        int m = floor(l + (r-l)/2);

        if (list[m] <= letter) {
            l = m+1;
        }
        else {
            min = list[m];
            r = m-1;
        }

    }

    cout << min;

    return 0;
}