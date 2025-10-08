#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> freq;
    unordered_map<int, int> sum_power, freq_sums;
    vector<int> powers;

    for (int i = 0; i < n; i++) {
        int power;
        cin >> power;
        freq[power]++;
    }

    int sum = 0, freq_sum = 0;
    for (auto [val, count]: freq) {
        sum += val*count;
        freq_sum += count;
        sum_power[val] = sum;
        freq_sums[val] = freq_sum;
        powers.push_back(val);
    }

    auto get = [&](int val) {
        int left = 0;
        int right = powers.size() - 1;
        int last_val = -1;

        while (left <= right) {
            int middle = floor(left + (right-left)/2);

            if (powers[middle] < val) {
                last_val = powers[middle];
                left = middle+1;
            }
            else if (powers[middle] > val) {
                right = middle-1;
            }
            else {
                last_val = powers[middle];
                break;
            }
        }

        return last_val;
    };

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int power, ind;
        cin >> power;
        ind = get(power);
        cout << freq_sums[ind] << " " << sum_power[ind] << endl;
    }

    return 0;
}