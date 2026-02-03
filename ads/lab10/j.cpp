#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> parent(n+1, 0), sz(n+1, 0), used(n+1, 0);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;

        vector<int> comp;
        queue<int> q;
        q.push(i);
        used[i] = 1;
        comp.push_back(i);

        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int to : g[v]) {
                if (!used[to]) {
                    used[to] = 1;
                    q.push(to);
                    comp.push_back(to);
                }
            }
        }

        int root = *min_element(comp.begin(), comp.end());
        queue<int> qq;
        qq.push(root);
        parent[root] = 0;

        vector<int> vis(n+1,0);
        vis[root] = 1;

        while (!qq.empty()) {
            int v = qq.front(); qq.pop();
            for (int to : g[v]) {
                if (!vis[to]) {
                    vis[to] = 1;
                    parent[to] = v;
                    sz[v]++;
                    qq.push(to);
                }
            }
        }
    }

    for (int v = 1; v <= n; v++) {
        if (parent[v] == 0) ans++;
        else if (sz[v] > sz[parent[v]]) ans++;
    }

    cout << ans;
    return 0;
}
