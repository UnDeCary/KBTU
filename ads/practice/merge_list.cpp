xx                                                                       
using namespace std;





int main() {
    int H, W, M;

    int mines_placed = 0;

    bool rand_place = true;
    vector<vector <int>> matrix;

    for (int i = 0; i < H; i++){
        for (int j = 0 ; i < W; j++) {
                if (rand_place && mines_placed < M && matrix[i][j] != -1) {
                    matrix[i][j] = -1;
                    mines_placed++;
                }
                else if (mines_placed >= M) {
                    break;
                }
                0 - 1
                if (randint() < 0.40) {
                    rand_place = !rand_place;
                }

        }
        if (mines_placed >= M) {
            break;
        }
    }


    return 0;
}