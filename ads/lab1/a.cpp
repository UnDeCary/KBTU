#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> decks(n);
    vector<vector<int>> output_decks(n);

    for (int i = 0; i < n; i++) {
        cin >> decks[i];
    }

    for (int i = 0; i < n; i++) {
        vector<int> output(decks[i]);
        if (decks[i] == 1) {
            output[0] = 1;
            output_decks[i] = output;
            continue;
        }

        int num_to_input = 2, ind = 1, shift = 3;

        output[1] = 1;

        while (true) {
            if (ind >= output.size()) {
                ind = 0;
            }

            if (output[ind] == 0) {
                shift--;
            }

            if (shift == 0 && output[ind] != 0) {
                cout << "IMPOSSIBLE" << endl;
                break;
            }

            if (shift == 0 && output[ind] == 0) {
                output[ind] = num_to_input;
                
                if ( num_to_input < decks[i] ) {
                    num_to_input++;
                    shift = num_to_input+1;
                }
                else {
                    output_decks[i] = output;
                    break;
                }
            }

            ind++;

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < decks[i]; j++) {
            cout << output_decks[i][j] << " ";
        }
        cout << endl;
    }
}