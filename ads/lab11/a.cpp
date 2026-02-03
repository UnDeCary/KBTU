#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Segment {
    int L, R, C;
};

vector<int> parent;
long long mst_cost = 0;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

bool unite_sets(int a, int b, int cost) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
        mst_cost += cost;
        return true;
    }
    return false;
}

vector<int> next_unite;
int find_next(int v) {
    if (v == next_unite[v]) {
        return v;
    }
    return next_unite[v] = find_next(next_unite[v]);
}

void solve() {

    int N, M;
    cin >> N >> M;

    vector<Segment> segments(M);
    for (int i = 0; i < M; ++i) {
        cin >> segments[i].L >> segments[i].R >> segments[i].C;
    }

    sort(segments.begin(), segments.end(), [](const Segment& a, const Segment& b) {
        return a.C < b.C;
    });

    parent.resize(N + 1);
    iota(parent.begin(), parent.end(), 0);
    mst_cost = 0;

     next_unite.resize(N + 1);
    iota(next_unite.begin(), next_unite.end(), 0);

    for (const auto& seg : segments) {
        int L = seg.L;
        int R = seg.R;
        int C = seg.C;

        int u = find_next(L);

        while (u < R) {
            int v = u + 1;

            if (find_set(u) != find_set(v)) {
                unite_sets(u, v, C);
            }

            int next_u = find_next(u + 1);

            if (find_set(u) == find_set(v)) {
                next_unite[u] = next_u;
            }
            u = next_u;
        }
    }

    cout << mst_cost << endl;
}

int main() {
    solve();
    return 0;
}