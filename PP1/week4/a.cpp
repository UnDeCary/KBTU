// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Write C++ code here
    int n;
    
    cin >> n;
    
    char a[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    
    string result = "";
    
    while (true) {
        if ( n < 16 ) {
            if (n > 9) {
                result += a[n-10];
            }
            else {
                result += n;
            }
            break;
        }
        if ( n%16 > 9) {
            result += a[n%16 - 10];
        }
        else {
            result += n%16;
        }
        n /= 16;
        cout << result << endl;
    }
    
    cout << result;
    return 0;
}