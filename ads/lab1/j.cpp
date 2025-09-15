#include <iostream>
#include <deque>


using namespace std;

int main() {
    char op;
    int num, last, front;
    deque<int> dq;

    while (true) {
        cin >> op;

        if (op == '!') {
            break;
        }

        if (op == '*') {
            if (dq.size() < 1) {
                cout << "error" << endl;
                continue;
            }

            last = dq.back();
            front = dq.front();

            dq.pop_back();
            if (dq.size() != 0) {
                dq.pop_front();
            }
            cout << last + front << endl;
            continue;
        }

        cin >> num;

        if (op == '+') {
            dq.push_front(num);
        }
        else if (op == '-') {
            dq.push_back(num);
        }
    }


    return 0;
}