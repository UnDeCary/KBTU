#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int variants = 1;

int minKey(vector<int> D, vector<bool> inMST) {
    int min = INT_MAX, min_index, inc = 1;

    for (int v = 0; v < inMST.size(); v++)
        if (inMST[v] == false && D[v] < min) {
            min = D[v], min_index = v;
            inc = 1;
        }
        else if (inMST[v] == false && D[v] == min) {
            inc++;
        }

    variants *= inc;

    return min_index;
}

void PRIM_MST(vector<vector<int>> &G, int v) {
    vector<bool> inMST(v, false);
    vector<int> D(v, INT_MAX);

    D[0] = 0;

    for (int i = 0; i < v - 1; i++) {
        int next = minKey(D, inMST);

        inMST[next] = true;
        for (int j = 0; j < v; j++) {
            if (G[next][j] != 0 && !inMST[j] && G[next][j] < D[j]) {
                D[j] = G[next][j];
            }
        }
    }

    for (int i = 0; i < v; i ++) {
        cout << i << " " << D[i] << endl;
    }
}


int main() {
    vector<vector<int>> G = {
        {0, 3, 0, 3},
        {3, 0, 3, 0},
        {0, 3, 0, 3},
        {3, 0, 3, 0}
    };

    PRIM_MST(G, G.size());

    cout << "Total variants: " << variants << endl;
    return 0;
}