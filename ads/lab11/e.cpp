#include <iostream>
#include <vector>

using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n, 0) {
        for(int i = 0; i < n; i++) p[i] = i;
    }
    
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(r[a] < r[b]) swap(a, b);
        p[b] = a;
        if(r[a] == r[b]) r[a]++;
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> active(n, false);
    vector<int> result(n + 1, 0);
    DSU dsu(n);
    
    int components = 0;
    

    for(int i = n - 1; i >= 0; i--) {
        active[i] = true;
        components++;

        for(int neighbor : adj[i]) {
            if(active[neighbor]) {
                if(dsu.unite(i, neighbor)) {
                    components--; 
                }
            }
        }

        result[i] = components;
    }

    for(int i = 1; i <= n; i++) {
        cout << result[i] << endl;
    }
    
    return 0;
}