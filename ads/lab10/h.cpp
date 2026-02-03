#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int n, m;
vector<vector<char>> grid;

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (grid[x][y] != '1') return;
    grid[x][y] = '0';
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}

int main() {
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int islands = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                islands++;
                dfs(i, j);
            }
        }
    }

    cout << islands << endl;
    return 0;
}