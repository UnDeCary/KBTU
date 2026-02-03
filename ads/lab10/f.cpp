#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> al;
    unordered_set<int> v;
    queue<int> q;

    for (int i = 0; i < m; i++) {
        int f, t;
        cin >> f >> t;
        al[f].push_back(t);
        al[t].push_back(f);
    }

    int start, end;
    cin >> start >> end;

    q.push(start);
    v.insert(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int el : al[cur]) {
            if (el == end) {
                cout << "YES" << endl;
                return 0;
            }

            if (!v.count(el)) {
                q.push(el);
                v.insert(el);
            }
        }
    }

    cout << "NO" << endl;

    return 0;

}
