#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main() {
    stack<char> st;
    string a;
    cin >> a;

    for (int i = 0; i < a.length(); i++) {
        if (st.empty() || st.top() != a[i]) {
            st.push(a[i]);
        }

        else if (st.top() == a[i]) {
            st.pop();
            continue;
        }
    }

    if (st.empty()) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }


    return 0;
}