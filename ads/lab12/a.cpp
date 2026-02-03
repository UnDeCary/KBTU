#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const long long INF = 1e9; 

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1)); 

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> dist[i][j];
        }
    }

    vector<int> add_order(n);
    for (int i = 0; i < n; ++i) {
        cin >> add_order[i];
    }
    
    vector<long long> results(n);
    vector<bool> is_added(n + 1, false);

    for (int i = 0; i < n; ++i) {
        int k = add_order[i];
        is_added[k] = true;

        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                if (dist[u][k] != INF && dist[k][v] != INF) {
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }

        long long current_longest_shortest_path = 0;

        for (int u = 1; u <= n; ++u) {
            if (!is_added[u]) continue; 
            
            for (int v = 1; v <= n; ++v) {
                if (!is_added[v]) continue;

                if (dist[u][v] != INF) {
                    current_longest_shortest_path = max(current_longest_shortest_path, dist[u][v]);
                }
            }
        }

        results[i] = current_longest_shortest_path;
    }

    for (int i = 0; i < n; ++i) {
        cout << results[i] << endl;
    }

    return 0;
}