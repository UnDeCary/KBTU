#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int N;
        cin >> N;
        vector<int> freq(26, 0);
        queue<char> q;
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            freq[c - 'a']++;
            q.push(c);

            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }

            if (q.empty()) cout << -1 << " ";
            else cout << q.front() << " ";
        }
        cout << endl;
    }

    return 0;
}