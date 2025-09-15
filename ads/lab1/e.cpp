#include <iostream>
#include <queue>

using namespace std;


int main() {
    queue<int> boris, nursik;
    int steps = 0;
    
    for (int i = 0; i < 5; i++) {
        int val;
        cin >> val;
        boris.push(val);
    }

    for (int i = 0; i < 5; i++) {
        int val;
        cin >> val;
        nursik.push(val);
    }

    while (!boris.empty() && !nursik.empty()) {
        steps++;
        
        int b = boris.front();
        boris.pop();
        int n = nursik.front();
        nursik.pop();
        
        if (steps > 1000000) {
            cout << "blin nichya";
            return 0;
        }

        if (b == 0 && n == 9) {
            boris.push(b);
            boris.push(n);
        }
        else if (b == 9 && n == 0) {
            nursik.push(b);
            nursik.push(n);
        }
        else if (b > n) {
            boris.push(b);
            boris.push(n);
        }
        else {
            nursik.push(b);
            nursik.push(n);
        }
    }

    if (boris.empty()) {
        cout << "Nursik " << steps;
        return 0;
    }
    cout << "Boris " << steps;
    
    return 0;
}