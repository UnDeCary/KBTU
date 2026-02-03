#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        long long k;
        cin >> s >> k;
        int n = s.size();

        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }

        long long overlap = pi[n - 1];
        long long add = n - overlap;

        long long ans = n + (k - 1) * add;
        cout << ans << "\n";
    }
    return 0;
}
