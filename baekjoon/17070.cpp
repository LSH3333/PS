#include <iostream>
using namespace std;

int N;
int board[20][20];
int hor[20][20], ver[20][20], diag[20][20];



int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // ?? ??
    hor[0][1] = 1;

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            // ?? ???
            // ?? ??
            if(c+1 < N && board[r][c+1] == 0) {
                hor[r][c+1] += hor[r][c];
            }
            // ??? ??
            if(r+1 < N && c+1 < N && board[r][c+1] == 0 && board[r+1][c+1] == 0&& board[r+1][c] == 0) {
                diag[r+1][c+1] += hor[r][c];
            }
            if(hor[r][c] > 0) {

            }

            // ?? ???
            // ?? ??
            if(r+1 < N && board[r+1][c] == 0) {
                ver[r+1][c] += ver[r][c];
            }
            // ??? ??
            if(r+1 < N && c+1 < N && board[r][c+1] == 0 && board[r+1][c+1] == 0&& board[r+1][c] == 0) {
                diag[r+1][c+1] += ver[r][c];
            }

            // ??? ???
            // ?? ??
            if(c+1 < N && board[r][c+1] == 0) {
                hor[r][c+1] += diag[r][c];
            }
            // ?? ??
            if(r+1 < N && board[r+1][c] == 0) {
                ver[r+1][c] += diag[r][c];
            }
            // ??? ??
            if(r+1 < N && c+1 < N && board[r][c+1] == 0 && board[r+1][c+1] == 0&& board[r+1][c] == 0) {
                diag[r+1][c+1] += diag[r][c];
            }
        }
    }

    cout << hor[N-1][N-1] + ver[N-1][N-1] + diag[N-1][N-1];

}