#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main() {
    int n, m, mines;
    cin >> n >> m;
    cin >> mines;

    vector<pair<int, int>> cordinates;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cordinates.push_back({i, j});
        }
    }

    random_device rd;
    mt19937 gen(rd());
    shuffle(cordinates.begin(), cordinates.end(), gen);

    for (int i = 0; i < mines; i++) {
        int x = cordinates[i].first, y = cordinates[i].second;
        matrix[x][y] = 9;

        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                if (n <= x+j || x+j < 0 || m <= y+k || y+k < 0) {
                    continue;
                }

                if (matrix[x+j][y+k] == 9) {
                    continue;
                }

                matrix[x+j][y+k]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}