#include <vector>
#include <iostream>

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
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    Hasher hasher(s);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        ull target = hasher.get(l, r);
        int len = r - l;
        int count = 0;

        for (int i = 0; i + len <= n; i++) {
            if (hasher.get(i, i + len) == target)
                count++;
        }
        cout << count << "\n";
    }
}