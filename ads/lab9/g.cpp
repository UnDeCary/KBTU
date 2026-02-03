#include <iostream>
#include <vector>

using namespace std;

int main() {
    string T;
    cin >> T;
    int n = T.size();

    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && T[i] != T[j])
            j = pi[j - 1];
        if (T[i] == T[j]) j++;
        pi[i] = j;
    }

    int p = n - pi[n - 1];

    bool ok = true;
    for (int i = p; i < n; i++) {
        if (T[i] != T[i - p]) {
            ok = false;
            break;
        }
    }

    if (!ok) p = n;

    cout << p << "\n";
    return 0;
}
