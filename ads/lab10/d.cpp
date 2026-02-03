#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    unordered_map<int, vector<int>> al;
    for (int i = 0; i < m; i++) {
        int f, t;
        cin >> f >> t;
        al[f].push_back(t);
        al[t].push_back(f);
    }

    const int INF = 1e9;
    vector<int> dist(n + 1, INF);
    queue<int> bfs;

    while (q--) {
        int op, node;
        cin >> op >> node;

        if (op == 1) {
            if (dist[node] != 0) {
                dist[node] = 0;
                bfs.push(node);
                while (!bfs.empty()) {
                    int cur = bfs.front();
                    bfs.pop();
                    for (int nxt : al[cur]) {
                        if (dist[nxt] > dist[cur] + 1) {
                            dist[nxt] = dist[cur] + 1;
                            bfs.push(nxt);
                        }
                    }
                }
            }
        } else {
            if (dist[node] == INF) cout << -1 << endl;
            else cout << dist[node] << endl;
        }
    }

    return 0;
}