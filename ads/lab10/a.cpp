#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, times = 0, mario_per_time = 0;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    queue<pair<int, int>> marios;
    vector<pair<int, int>> cords = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2) {
                marios.push({i, j});
                mario_per_time++;
            }
        }
    }

    while (!marios.empty()) {
        int m_p_q = 0;
        bool inc = false;
        
        for (int t = 0; t < mario_per_time; t++) {
            int x = marios.front().first;
            int y = marios.front().second;

            for (auto c : cords) {
                if (x + c.first >= n || x + c.first < 0 || y + c.second >= m || y + c.second < 0) {
                    continue;
                }

                if (matrix[x+c.first][y+c.second] == 1) {
                    matrix[x+c.first][y+c.second]++;
                    marios.push({x+c.first, y+c.second});
                    m_p_q++;
                    inc = true;
                }
            }
            marios.pop();
        }
        if (inc) {
            times++;
        }
        mario_per_time = m_p_q;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << times << endl;

    return 0;
}