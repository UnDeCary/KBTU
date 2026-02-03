#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

struct Edge {
    long long cost;
    int u, v;
};

vector<int> parent;
vector<int> rank_dsu;

void init_dsu(int n) {
    parent.resize(n + 1);
    rank_dsu.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

bool unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_dsu[a] < rank_dsu[b])
            swap(a, b);
        parent[b] = a;
        if (rank_dsu[a] == rank_dsu[b])
            rank_dsu[a]++;
        return true;
    }
    return false;
}


int main() {
    int N, M;
    cin >> N >> M;

    long long B, S;
    cin >> B >> S;

    vector<Edge> edges;

    for (int i = 0; i < M; ++i) {
        string type;
        int u, v;
        long long L;
        cin >> type >> u >> v >> L;

        long long cost;

        if (type == "both") {
            cost = L * min(B, S);
        } else if (type == "big") {
            cost = L * B;
        } else if (type == "small") {
            cost = L * S;
        } else {
            continue; 
        }

        edges.push_back({cost, u, v});
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.cost < b.cost;
    });

    init_dsu(N);

    long long total_mst_cost = 0;
    int edges_count = 0;

    for (const auto& edge : edges) {
        if (unite_sets(edge.u, edge.v)) {
            total_mst_cost += edge.cost;
            edges_count++;
            
            if (edges_count == N - 1) {
                break;
            }
        }
    }

    cout << total_mst_cost << endl;

    return 0;
}