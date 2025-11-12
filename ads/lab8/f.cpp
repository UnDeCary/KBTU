#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using ull = unsigned long long;

struct Hasher {
    vector<ull> h, p;
    static const ull BASE = 1315423911;

    Hasher(const string &s) {
        int n = s.size();
        h.resize(n + 1, 0);
        p.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i + 1] = h[i] * BASE + s[i];
            p[i + 1] = p[i] * BASE;
        }
    }

    ull get(int l, int r) {
        return h[r] - h[l] * p[r - l];
    }
};

int main() {
    string s;
    cin >> s;
    int n = s.size();
    Hasher hasher(s);

    unordered_set<ull> st;
    st.reserve(n * (n + 1) / 2);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            st.insert(hasher.get(i, j));
        }
    }

    cout << st.size() << endl;
}
