#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, K = 0, S = 0;
    char cur;
    cin >> n;

    string s;
    cin >> s;
    
    for (int i = n-1; i >= 0; i--) {
        cur = s[i];
        if (cur == 'K') {
            K++;
            if (S > 0) {
                S--;
            }
        }
        else {
            S++;
            if (K > 0) {
                K--;
            }
        }
    }

    if (K > S) {
        cout << "KATSURAGI";
    }
    else {
        cout << "SAKAYANAGI";
    }
    return 0;
}