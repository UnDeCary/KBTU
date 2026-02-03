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
    string textm = text;
    while (textm.size() < pattern.size()*2) {
        textm += text;
    }
    int n = textm.length();

    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0;

    while (i < n) {
        if (textm[i] == pattern[j]) {
            if (j == pattern.size()-1) {
                return i/(text.size()) + 1;
            }
            i++;
            j++;
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
    string a, b;
    cin >> a >> b;
    
    cout << search(b, a) << endl;

    return 0;
}