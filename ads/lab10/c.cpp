#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    stack<int> s;

    cin >> a >> b;

    int x = b;
    while (x > a) {
        s.push(x);
        if (x % 2 == 1) {
            x++;
        }
        else {
            x = x/2;
        }
    }

    while (x < a) {
        s.push(x);
        x++;
    }

    cout << s.size() << endl;
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

    cout << endl;
    return 0;
}

