#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <limits>
#include <numeric>

using namespace std;

typedef long long Distance;

const Distance UNREACHABLE = numeric_limits<Distance>::max(); 

struct City {
    int x, y;
};

Distance manhattanDistance(const City& c1, const City& c2) {
    return (Distance)abs(c1.x - c2.x) + (Distance)abs(c1.y - c2.y);
}

bool canReach(int startVertex, int endVertex, int N, const vector<City>& cities, Distance maxWeight) {
    if (startVertex == endVertex) return true;

    vector<bool> visited(N + 1, false);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == endVertex) return true;

        for (int v = 1; v <= N; ++v) {
            if (u == v || visited[v]) continue;

            Distance weight = manhattanDistance(cities[u], cities[v]);
            
            if (weight <= maxWeight) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    vector<City> cities(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> cities[i].x >> cities[i].y;
    }

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<Distance> unique_weights;
    Distance max_possible_weight = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            Distance w = manhattanDistance(cities[i], cities[j]);
            unique_weights.push_back(w);
            max_possible_weight = max(max_possible_weight, w);
        }
    }

    Distance low = 0;
    Distance high = max_possible_weight;
    Distance minRequiredAge = -1;

    while (low <= high) {
        Distance mid = low + (high - low) / 2;
        
        if (canReach(1, N, N, cities, mid)) {
            minRequiredAge = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << minRequiredAge << endl;
    
    return 0;
}