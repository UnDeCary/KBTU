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

vector<int> search(string pattern, string text) {
    int n = text.length();

    vector<int> lps = computeLPS(pattern);

    vector<int> idx;

    int i = 0, j = 0;

    while (i < n) {
        
        if (text[i] == pattern[j]) {
            if (j == pattern.size()-1) {
                idx.push_back(i-j+1);
                j = 0;
            }
            else {
                j++;
            }
            
            i++;
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

    return idx;
}


int main() {
    string pattern, text;
    cin >> text >> pattern;

    vector<int> idx = search(pattern, text);

    cout << idx.size() << endl;
    for (int i = 0; i < idx.size(); i++) {
        cout << idx[i] << " ";
    }

    return 0;
}