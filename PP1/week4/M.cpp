#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int j = 0; j < n; j++) {
        if (a[j] != a[j+1]) {
            cout << a[j] << " ";
        }
    }

    return 0;
}