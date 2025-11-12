#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ull = unsigned long long;

struct Hasher {
    vector<ull> h, p;
    static const ull BASE = 131;

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
    string s1, s2, p;
    cin >> s1 >> s2 >> p;

    int n1 = s1.size();
    int n2 = s2.size();
    int m = p.size();

    Hasher hs1(s1), hs2(s2), hp(p);
    ull h_parasite = hp.get(0, m);

    int count = 0;
    int maxPos = min(n1, n2) - m;

    for (int i = 0; i <= maxPos; i++) {
        if (hs1.get(i, i + m) == h_parasite && hs2.get(i, i + m) == h_parasite) {
            count++;
        }
    }

    cout << count << endl;
}