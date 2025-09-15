#include <iostream>

using namespace std;

int main() {
    string a, b, ao, bo;
    int a_backspace = 0, b_backspace = 0;

    cin >> a >> b;

    for (int i = a.length()-1; i >= 0; i--) {
        if (a[i] == '#') {
            a_backspace++;
            continue;
        }
        else {
            if (a_backspace > 0) {
                a_backspace--;
                continue;
            }
            else {
                ao += a[i];
                continue;
            }
        }
    }

    for (int i = b.length()-1; i >= 0; i--) {
        if (b[i] == '#') {
            b_backspace++;
            continue;
        }
        else {
            if (b_backspace > 0) {
                b_backspace--;
                continue;
            }
            else {
                bo += b[i];
                continue;
            }
        }
    }

    if (ao == bo) {
        cout << "Yes" << endl;
    } else { cout << "No" << endl; }

    return 0;
}