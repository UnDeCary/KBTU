#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, cycle = 0;
    cin >> n >> m;

    unordered_map<int, vector<int>> al;
    unordered_set<int> v;
    queue<int> q;

    int f, t;

    for (int i = 0; i < m; i++) {
        
        cin >> f >> t;
        al[f].push_back(t);
    }

    q.push(f);
    v.insert(f);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int el : al[cur]) {

            if (!v.count(el)) {
                q.push(el);
                v.insert(el);
            }

            else {
                if (cycle != 0) {
                    cout << "NO" << endl;
                    return 0;
                }
                cycle++;
            }
        }
    }

    cout << "YES" << endl;

    return 0;

}
