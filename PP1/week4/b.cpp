#include <iostream>

using namespace std;

int main() {

    int n = 0;

    int size = 10;

    int a[size] = {};

    int temp;

    while (cin>>temp) {
        a[n] = temp;
        ++n;
    }

    for (auto i:a) {
        cout << i << " ";
    }

    cout << endl;


    return 0;
}