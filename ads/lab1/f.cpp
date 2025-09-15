#include <iostream>
#include <math.h>

using namespace std;


int main() {
    int n, p = 1, i = 0, number = 2;
    bool is_prime;
    cin >> n;
    

    for (;;number++)
    {
        if (i == n) {
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
            i++;
            p = number;
        }
    }

    return 0;
    
}