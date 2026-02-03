#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

typedef long long Distance;
const Distance UNREACHABLE = numeric_limits<Distance>::max(); 

typedef pair<Distance, int> QueuePair; 

vector<Distance> findShortestPaths(int startVertex, int vertexCount, const vector<vector<QueuePair>>& graph) {
    vector<Distance> distances(vertexCount + 1, UNREACHABLE);
    distances[startVertex] = 0;

    priority_queue<QueuePair, vector<QueuePair>, greater<QueuePair>> pq;
    pq.push({0, startVertex});

    while (!pq.empty()) {
        Distance currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        if (currentDistance > distances[currentVertex]) continue;

        for (const auto& edge : graph[currentVertex]) {
            int neighborVertex = edge.first;
            Distance weight = edge.second;

            if (distances[currentVertex] != UNREACHABLE && distances[currentVertex] <= UNREACHABLE - weight) {
                Distance newDistance = distances[currentVertex] + weight;
                if (newDistance < distances[neighborVertex]) {
                    distances[neighborVertex] = newDistance;
                    pq.push({newDistance, neighborVertex});
                }
            }
        }
    }
    return distances;
}

int main() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<QueuePair>> graph(vertexCount + 1); 

    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        Distance w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int start, merchant, pharmacy, end;
    if (!(cin >> start >> merchant >> pharmacy >> end)) return 0;
    
    vector<Distance> distFromStart = findShortestPaths(start, vertexCount, graph);
    vector<Distance> distFromMerchant = findShortestPaths(merchant, vertexCount, graph);
    vector<Distance> distFromPharmacy = findShortestPaths(pharmacy, vertexCount, graph);
    
    Distance minTotalDistance = UNREACHABLE;

    Distance R_to_P = distFromStart[pharmacy];
    Distance P_to_M = distFromPharmacy[merchant];
    Distance M_to_G = distFromMerchant[end];
    
    if (R_to_P != UNREACHABLE && P_to_M != UNREACHABLE && M_to_G != UNREACHABLE) {
        if (R_to_P <= UNREACHABLE - P_to_M && R_to_P + P_to_M <= UNREACHABLE - M_to_G) {
            minTotalDistance = min(minTotalDistance, R_to_P + P_to_M + M_to_G);
        }
    }
    
    Distance R_to_M = distFromStart[merchant];
    Distance M_to_P = distFromMerchant[pharmacy];
    Distance P_to_G = distFromPharmacy[end];

    if (R_to_M != UNREACHABLE && M_to_P != UNREACHABLE && P_to_G != UNREACHABLE) {
        if (R_to_M <= UNREACHABLE - M_to_P && R_to_M + M_to_P <= UNREACHABLE - P_to_G) {
            minTotalDistance = min(minTotalDistance, R_to_M + M_to_P + P_to_G);
        }
    }

    if (minTotalDistance == UNREACHABLE) {
        cout << -1 << endl;
    } else {
        cout << minTotalDistance << endl;
    }

    return 0;
}