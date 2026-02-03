#include<iostream>
#include <vector>

using namespace std;

string to_lower_str(const string &s) {
    string t = s;
    for (char &c : t) if ('A' <= c && c <= 'Z') c = char(c - 'A' + 'a');
    return t;
}

int main() {
    string P;
    if (!(cin >> P)) return 0;

    int N;
    cin >> N;
    vector<string> cities(N);
    for (int i = 0; i < N; ++i) cin >> cities[i];

    string lowP = to_lower_str(P);
    int L = (int)lowP.size();

    int best = 0;
    vector<string> result;

    for (int i = 0; i < N; ++i) {
        const string &orig = cities[i];
        string lowC = to_lower_str(orig);

        int maxMatch = 0;
        for (int len = 1; len <= L; ++len) {
            if ((int)lowC.size() < len) break;
            bool ok = true;
            for (int k = 0; k < len; ++k) {
                if (lowP[L - len + k] != lowC[k]) { ok = false; break; }
            }
            if (ok) maxMatch = len;
        }

        if (maxMatch > best) {
            best = maxMatch;
            result.clear();
            if (maxMatch > 0) result.push_back(orig);
        } else if (maxMatch == best && maxMatch > 0) {
            result.push_back(orig);
        }
    }

    cout << result.size() << "\n";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}