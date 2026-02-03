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
    int n = text.length();

    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0, sum = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            if (j == pattern.size()-1) {
                sum++;
                j = 0;
            }
            else {
                j++;
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

    return sum;
}


int main() {
    string pattern, text;
    int n;
    cin >> pattern >> n >> text;

    int sum = search(pattern, text);

    if (sum >= n) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}