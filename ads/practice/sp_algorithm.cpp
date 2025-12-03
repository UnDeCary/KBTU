#include <iostream>
#include <vector>
#include <priority_queue>

using namespace std;

vector<int> dijkstra(vector<vector<pair<double, int>>>& adj, int src) {

    int V = adj.size();
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    vector<int> D(V, INT_MAX);
    vector<bool> vis(V, false);

    D[src] = 0;
    pq.emplace({0, src});

    while (!pq.empty()) {
        auto & w, u = pq.top();
        pq.pop();

        if (vis[u]) continue;

        vis[u] = true;

        for (auto& e : adj[u]) {
            if (!vis[e.second] && D[u] + e.first < D[e.second]) {
                D[e.second] = D[u] + e.first;
                pq.emplace({D[e.second], e.second});
            }
        }
    }

    return D;
}


int main() {
    vector<vector<pair<int, char>>> matrix = {
        {{1, 'D'}, {1, 'D'}, {1, 'H'}, {0, 'D'}},
        {{1, 'H'}, {0, 'N'}, {1, 'H'}, {1, 'D'}},
        {{1, 'H'}, {1, 'H'}, {1, 'N'}, {1, 'N'}},
        {{1, 'D'}, {0, 'D'}, {1, 'D'}, {1, 'H'}}
    }

    vector<vector<pair<double, int>>> adj;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            auto & w, mod = matrix[i][j];
            adj[]
        }
    }


    return 0;
}