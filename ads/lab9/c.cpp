#include <iostream>
#include <vector>

using namespace std;


vector<int> computeLPS(string pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int search(string pattern, string text) {
    
    string text2 = text + text;
    int n = text2.length();
    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0;

    while (i < n) {
        if (text2[i] == pattern[j]) {
            i++;
            j++;

            if (j == pattern.size()) {
                return i - j;
            }
            
        }
        else {
            if (j > 0) {
                j = lps[j-1];
            }
            else {
                i++;
            }
        }
    }

    return -1;
}

int main() {
    string pattern, text;
    cin >> text >> pattern;

    int idx = search( pattern, text );

    if (idx == -1 || idx >= text.size()) {
        cout << -1;
        return 0;
    }

    int right_shift = (text.size() - idx) % text.size();

    cout << right_shift;

    return 0;
}