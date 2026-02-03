#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int bfs(int start, int end, int n, const vector<vector<int>>& adj) {
    if (start == end) return 0;

    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == end) {
            return dist[u];
        }

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> is_airline(n + 1, vector<bool>(n + 1, false));
    vector<vector<int>> olzhas_adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        is_airline[u][v] = is_airline[v][u] = true;
        olzhas_adj[u].push_back(v);
        olzhas_adj[v].push_back(u);
    }

    vector<vector<int>> nugman_adj(n + 1);
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            if (u != v && !is_airline[u][v]) {
                nugman_adj[u].push_back(v);
            }
        }
    }

    int start_node = 1;
    int end_node = n;

    int nugman_dist = bfs(start_node, end_node, n, nugman_adj);
    int olzhas_dist = bfs(start_node, end_node, n, olzhas_adj);

    if (nugman_dist == -1 || olzhas_dist == -1) {
        cout << -1 << endl;
    } else {
        cout << max(nugman_dist, olzhas_dist) << endl;
    }

    return 0;
}