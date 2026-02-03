#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<long long> ducks(N);
    for (int i = 0; i < N; ++i) {
        cin >> ducks[i];
    }

    long long sum_D = 0;
    for (long long d : ducks) {
        sum_D += d;
    }

    long long min_D = -1;
    if (N > 0) {
        min_D = ducks[0];
        for (long long d : ducks) {
            if (d < min_D) {
                min_D = d;
            }
        }
    }

    long long total_cost = 0;
    
    if (N == 1) {
        total_cost = 0;
    } else {
        total_cost = sum_D + (long long)(N - 2) * min_D;
    }

    cout << total_cost << endl;
    
    return 0;
}