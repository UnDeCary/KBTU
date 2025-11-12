#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;

struct Hasher {
    vector<ull> h, p;
    static const ull BASE = 1315423911ULL;

    Hasher(const string &s) {
        int n = s.size();
        h.resize(n + 1, 0);
        p.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i + 1] = h[i] * BASE + (unsigned char)s[i];
            p[i + 1] = p[i] * BASE;
        }
    }

    ull get(int l, int r) const {
        return h[r] - h[l] * p[r - l];
    }
};

int main() {
    string big;
    cin >> big;
    int n;
    cin >> n;
    vector<string> small(n);
    for (int i = 0; i < n; i++) cin >> small[i];

    int L = big.size();
    vector<bool> covered(L, false);

    Hasher hasher(big);

    for (const string &s : small) {
        int len = s.size();
        if (len > L) continue;
        Hasher hs(s);
        ull hval = hs.get(0, len);

        for (int i = 0; i + len <= L; i++) {
            if (hasher.get(i, i + len) == hval) {
                for (int j = i; j < i + len; j++) covered[j] = true;
            }
        }
    }

    bool ok = true;
    for (bool c : covered) if (!c) ok = false;

    cout << (ok ? "YES" : "NO") << endl;
}