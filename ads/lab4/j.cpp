#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
vector<long long> vals;


void cout_BST(int l, int r) {
    if (l > r) {
        return;
    }
    int m = (int) l + (r-l)/2;
    cout << vals[m] << " ";

    cout_BST(m+1, r);
    cout_BST(l, m-1);
}


int main() {
    int n;
    cin >> n;
    n = pow(2, n) - 1;

    for (int i = 0; i < n; i++) {
        long long val;
        cin >> val;
        vals.push_back(val);
    }

    sort(vals.begin(), vals.end());

    cout_BST(0, n-1);

     
    cout << endl;

    return 0;
}