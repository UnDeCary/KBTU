#include <iostream>
#include <vector>

using namespace std;

int main() {

    int k;
    cin >> k;
    vector<string> s(k);
    for (int i = 0; i < k; i++)
        cin >> s[i];

    int minIndex = 0;
    for (int i = 1; i < k; i++) {
        if (s[i].size() < s[minIndex].size())
            minIndex = i;
    }
    string base = s[minIndex];

    string ans = "";
    int n = base.size();

    for (int len = n; len >= 1; len--) {
        for (int i = 0; i + len <= n; i++) {
            string sub = base.substr(i, len);
            bool ok = true;
            for (int j = 0; j < k; j++) {
                if (j == minIndex) continue;
                if (s[j].find(sub) == string::npos) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << sub << endl;
                return 0;
            }
        }
    }
}