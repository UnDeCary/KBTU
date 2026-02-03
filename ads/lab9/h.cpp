#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computeZ(const string& s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    string s;
    cin >> s;
    
    int n = s.length();
    if (n < 3) {
        cout << 0;
        return 0;
    }
    
    vector<int> z = computeZ(s);
    long long count = 0;
    
    for (int i = 1; i <= n - 2; i++) {
        if (z[i] >= i && 2 * i < n) {
            count++;
        }
    }
    
    cout << count;
    return 0;
}