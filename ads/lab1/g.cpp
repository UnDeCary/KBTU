#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    int n, p = 1, i = 0, number = 2, z = 0;
    vector<int> primes;
    bool is_prime;
    cin >> n;
    

    for (;;number++)
    {
        if (z == n) {
            cout << p;
            return 0;
        }
        
        is_prime = true;
        
        for (int j = 2; j <= sqrt(number); j++) {

            if (number%j == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            primes.push_back(number);
            i++;

            
            for (int k = primes.size(); k >= 0; k--) {
                if (i == primes[k]) {
                    z++;
                    break;
                }
            }
            p = number;
        }
    }

    return 0;
    
}