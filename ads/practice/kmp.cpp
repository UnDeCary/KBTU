#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> LPS(string &pattern) {
    int n = pattern.size();
    int len = 0;
    int i = 1;

    vector<int> lps(n, 0);

    while (i < n) {
        if (pattern[len] == pattern[i]) {
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


int main() {
    string A, text, B;

    cin >> A >> text;

    B = text + text;
    cout << A << " " << text << " " << B;

    vector<int> lps_A;

    lps_A = LPS(A);

    int a = A.size();
    int b = B.size();

    cout << a << " " << b;

    int i = 0, j = 0;
    while (i < b) {

        if (B[i] == A[j]) {
            i++;
            j++;

            if (j == a) {
                cout << i-a << endl;
                return 0;
            }
        }
        else {
            if (j != 0) {
                j = lps_A[j-1];
            }
            else {
                j = 0;
            }
        }
    }

    return 0;

}