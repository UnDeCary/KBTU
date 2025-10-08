#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> left(n + 1, -1), right(n + 1, -1);

    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) left[x] = y;
        else right[x] = y;
    }

    queue<pair<int,int>> q;
    q.push({1, 1});

    vector<int> cnt(n + 1, 0);
    int ans = 0;

    while (!q.empty()) {
        auto [v, lvl] = q.front();
        q.pop();

        cnt[lvl]++;
        ans = max(ans, cnt[lvl]);

        if (left[v] != -1) q.push({left[v], lvl + 1});
        if (right[v] != -1) q.push({right[v], lvl + 1});
    }

    cout << ans << endl;
    return 0;
}
