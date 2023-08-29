#include <iostream>
using namespace std;

int N, horAns, verAns;
char board[101][101];
bool d1[101][101];
bool d2[101][101];

int Hor(int _r, int _c) {
    int cnt = 0;
    for(int c = _c; c < N; c++) {
        if(board[_r][c] == 'X') break;
        d1[_r][c] = true;
        cnt++;
    }
    return cnt;
}

int Ver(int _r, int _c) {
    int cnt = 0;
    for(int r = _r; r < N; r++) {
        if(board[r][_c] == 'X') break;
        d2[r][_c] = true;
        cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (board[i][j] == '.' && !d1[i][j]) {
                int cnt = Hor(i, j);
                if(cnt >= 2) horAns++;
            }

            if (board[i][j] == '.' && !d2[i][j]) {
                int cnt = Ver(i, j);
                if(cnt >= 2) verAns++;
            }
        }
    }



    cout << horAns << ' ' << verAns;
}