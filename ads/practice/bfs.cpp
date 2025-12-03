#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

int islands(unordered_map<int, vector<int>>& al) {
    unordered_map<int, bool> v;y
    queue<int> q;
    int sum_of_islands = 0;

    while (!al.empty()) {
        int s = al.begin()->first;
        q.push(s);
        v[s] = 1;
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int el : al[cur]) {
                if (!v[el]) {
                    q.push(el);
                    v[el] = 1;
                }
            }
            al.erase(cur);
        }
        sum_of_islands++;
    }
    
    
    return sum_of_islands;
}

int main() {
    vector<vector<int>> el = {{0, 1}, {1, 2}, {2, 3}, {0, 3}, {4, 5}, {5, 6}, {4, 6}, {7, 8}};
    unordered_map<int, vector<int>> al;
    for (vector<int> p : el) {
        al[p[0]].push_back(p[1]);
        al[p[1]].push_back(p[0]);

    }

    for (auto f : al) {
        cout << f.first << ": ";
        for (int s : f.second) {
            cout << s << " ";
        }
        cout << endl;
    }

    
    // al = {
    //     {0, {1, 2}},
    //     {1, {0, 2}},
    //     {2, {1, 3}},
    //     {3, {0, 2}},
    //     {4, {5, 6}},
    //     {5, {4, 6}},
    //     {6, {4, 5}},
    // };

    cout << islands(al) << endl;

    return 0;
}