#include <iostream>

using namespace std;

int main() {
    
    int w, h, n, count = 0;
    cin >> w >> h >> n;
    int a[n][4], main[h][w] = {};
    
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }
    
    for (auto array : a) {
        for (int i = array[1]; i < array[3]; i++) {
            for (int j = array[0]; j < array[2]; j++) {
                if (main[i][j] == 0) {
                    main[i][j] = 1;
                }
            }
        }
    }

    cout << endl;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (main[i][j] == 0) {
                count++;
            }
            cout << main[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << count;

    

    return 0;
}