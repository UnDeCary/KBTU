#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {

    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    string s;
    for (int i = 0; i < n; i++) {
        ll diff = h[i];
        if (i > 0) diff -= h[i - 1];
        ll ch = diff / (1LL << i);
        s.push_back(char(ch + 97));
    }

    cout << s << endl;
    return 0;
}