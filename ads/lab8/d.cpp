#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<string> patterns(n);
        for (int i = 0; i < n; i++) cin >> patterns[i];

        string text;
        cin >> text;

        vector<int> freq(n, 0);
        int max_freq = 0;

        for (int i = 0; i < n; i++) {
            const string &p = patterns[i];
            size_t pos = text.find(p, 0);
            while (pos != string::npos) {
                freq[i]++;
                pos = text.find(p, pos + 1);
            }
            max_freq = max(max_freq, freq[i]);
        }

        cout << max_freq << "\n";
        for (int i = 0; i < n; i++) {
            if (freq[i] == max_freq) cout << patterns[i] << endl;
        }
    }

    return 0;
}