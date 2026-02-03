#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x -= 1;
        y -= 1;
        z -= 1;

        if (a[x][y] == 0 || a[x][z] == 0 || a[y][z] == 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}
