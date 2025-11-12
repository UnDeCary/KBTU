#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> res;
    res.reserve(n + m);

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            res.push_back(a[i]);
            i++;
        } else {
            res.push_back(b[j]);
            j++;
        }
    }

    while (i < n) res.push_back(a[i++]);
    while (j < m) res.push_back(b[j++]);

    for (int k = 0; k < (int)res.size(); k++) {
        cout << res[k] << " ";
    }
    cout << endl;

    return 0;
}