#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> items_to_find(t);

    for (int i = 0; i < t; i++) {
        cin >> items_to_find[i];
    }

    int r, c;
    cin >> r >> c;
    vector<vector<int>> arr(r, vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    for (int e = 0; e < t; e++) {
        int r_left = 0, r_right = r - 1;
        bool found = false;

        while (r_left <= r_right) {
            int c_left = 0, c_right = c-1;
            int r_middle = floor(r_left + (r_right-r_left)/2);
            if (r_middle%2 == 0) {
                if (arr[r_middle][0] < items_to_find[e]) {
                    r_right = r_middle-1;
                }
                else if (arr[r_middle][c-1] > items_to_find[e]) {
                    r_left = r_middle+1;
                }
                else if (arr[r_middle][0] == items_to_find[e]) {
                    cout << r_middle << " " << 0 << endl;
                    found = true;
                    break;
                }
                else if (arr[r_middle][c-1] == items_to_find[e]) {
                    cout << r_middle << " " << c-1 << endl;
                    found = true;
                    break;
                    
                }
                else {
                    while (c_left <= c_right) {
                        int c_middle = floor(c_left + (c_right-c_left)/2);
                        if (arr[r_middle][c_middle] < items_to_find[e]) {
                            c_right = c_middle-1;
                        }
                        else if (arr[r_middle][c_middle] > items_to_find[e]) {
                            c_left = c_middle+1;
                        }
                        else {
                            cout << r_middle << " " << c_middle << endl;
                            found = true;
                            break;
                        }
                    }
                    break;
                    
                }

            }
            else {
                if (arr[r_middle][0] > items_to_find[e]) {
                    r_left = r_middle+1;
                }
                else if (arr[r_middle][c-1] < items_to_find[e]) {
                    r_right = r_middle-1;
                }
                else if (arr[r_middle][0] == items_to_find[e]) {
                    cout << r_middle << " " << 0 << endl;
                    found = true;
                    break;
                }
                else if (arr[r_middle][c-1] == items_to_find[e]) {
                    cout << r_middle << " " << c-1 << endl;
                    found = true;
                    break;
                }
                else {
                    while (c_left <= c_right) {
                        int c_middle = floor(c_left + (c_right-c_left)/2);
                        if (arr[r_middle][c_middle] < items_to_find[e]) {
                            c_left = c_middle+1;
                        }
                        else if (arr[r_middle][c_middle] > items_to_find[e]) {
                            c_right = c_middle-1;

                        }
                        else {
                            cout << r_middle << " " << c_middle << endl;
                            found = true;
                            break;
                        }
                    }
                    break;
                }
                
            }
        }
        if (!found) {
            cout << -1 << endl;
        }
    }


    return 0;
}