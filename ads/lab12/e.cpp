#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

typedef long long Weight;
const Weight INF = numeric_limits<Weight>::max();

struct Edge {
    int from;
    int to;
    Weight weight;
};

vector<int> findNegativeCycle(int N, const vector<Edge>& edges, vector<Weight>& dist, vector<int>& parent) {

    for (int i = 0; i < N; ++i) {
        for (const auto& edge : edges) {
            int u = edge.from;
            int v = edge.to;
            Weight w = edge.weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    int cycle_start = -1;
    for (const auto& edge : edges) {
        int u = edge.from;
        int v = edge.to;
        Weight w = edge.weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {

            int current = v;
            for(int i = 0; i < N; ++i) {
                current = parent[current];
            }
            cycle_start = current;
            break;
        }
    }

    if (cycle_start == -1) {
        return {};
    }

    vector<int> cycle;
    vector<bool> on_path(N + 1, false);
    
    int current = cycle_start;
    
    do {
        cycle.push_back(current);
        current = parent[current];
    } while (current != cycle_start);

    cycle.push_back(cycle_start);

    reverse(cycle.begin(), cycle.end());
    
    return cycle;
}

int main() {
    int N;
    cin >> N;

    vector<Edge> edges;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            Weight w;
            cin >> w;
            if (abs(w) < 100000) { 
                edges.push_back({i, j, w});
            }
        }
    }

    vector<Weight> dist(N + 1, 0);
    vector<int> parent(N + 1, 0); 
    
    vector<int> cycle = findNegativeCycle(N, edges, dist, parent);

    if (cycle.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << cycle.size() << endl;
        for (int i = 0; i < cycle.size(); ++i) {
            cout << cycle[i] << " ";
        }
        cout << endl;
    }

    return 0;
}