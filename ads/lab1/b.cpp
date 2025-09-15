#include <iostream>
#include <stack>

using namespace std;


int main() {
    int n, val;
    cin >> n;
    stack<int> younger;

    for (int i = 0; i < n; i++) {
        cin >> val;

        while (!younger.empty()) {
            if (younger.top() <= val) {
                cout << younger.top() << " ";
                younger.push(val);
                break;
            }

            younger.pop();
        }

        if (younger.empty()) {
            cout << -1 << " ";
            younger.push(val);
            continue;
        }
}

    return 0;
}