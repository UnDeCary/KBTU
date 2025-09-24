#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, max = 0;
    map<int, int> m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        m[val]++;
        if (m[val] > max) {
            max = m[val];
        }
    }

    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        if (it->second == max) {
            cout << it->first << " ";
        }
    }
    cout << endl;
    return 0;
}