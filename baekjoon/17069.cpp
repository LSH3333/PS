#include <iostream>
using namespace std;

#define HORZ 0
#define VERT 1
#define DIAG 2

int N;
long long d[3][33][33];
bool b[33][33];

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> b[i][j];
        }
    }

//    d[HORZ][1][1] = 1;
    d[HORZ][1][2] = 1;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            if(r == 1 && c == 1) continue;
            if(b[r][c]) continue;

            // HORZ
            if(c+1 <= N && !b[r][c+1]) {
                d[HORZ][r][c+1] += d[HORZ][r][c];
            }
            if (r + 1 <= N && c + 1 <= N && !b[r][c + 1] && !b[r + 1][c + 1] && !b[r + 1][c]) {
                d[DIAG][r+1][c+1] += d[HORZ][r][c];
            }

            // VERT
            if(r+1 <= N && !b[r+1][c]) {
                d[VERT][r+1][c] += d[VERT][r][c];
            }
            if (r + 1 <= N && c + 1 <= N && !b[r][c + 1] && !b[r + 1][c + 1] && !b[r + 1][c]) {
                d[DIAG][r+1][c+1] += d[VERT][r][c];
            }

            // DIAG
            if (c + 1 <= N && !b[r][c + 1]) {
                d[HORZ][r][c+1] += d[DIAG][r][c];
            }
            if (r + 1 <= N && !b[r + 1][c]) {
                d[VERT][r+1][c] += d[DIAG][r][c];
            }
            if (r + 1 <= N && c + 1 <= N && !b[r][c + 1] && !b[r + 1][c + 1] && !b[r + 1][c]) {
                d[DIAG][r+1][c+1] += d[DIAG][r][c];
            }
        }
    }


    cout << d[HORZ][N][N] + d[VERT][N][N] + d[DIAG][N][N];
}