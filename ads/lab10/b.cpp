#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
    int n, start, end, path = 0;
    unordered_map<int, vector<int>> al;
    unordered_set<int> v;
    queue<int> q;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (val == 1) {
                al[i+1].push_back(j+1);
            }
        }
    }

    cin >> start >> end;


    q.push(start);
    v.insert(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        path++;


        for (int el : al[cur]) {
            if (!v.count(el)) {
                q.push(el);
                v.insert(el);
                
                if (end == el) {
                    cout << path << endl;
                    return 0;
                }
            }
        }


    }


    cout << -1 << endl;
    return 0;
}