#include <iostream>
using namespace std;

int R, C;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
char board[11][11];

int beginR=-1, endR=-1, beginC=-1, endC=-1;

void FindBeginRow() {
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(board[r][c] == 'X' && beginR == -1) {
                beginR = r;
            }
            if(board[r][c] == 'X') {
                endR = r+1;
            }
        }
    }
}

void FindBeginCol() {
    for(int c = 0; c < C; c++) {
        for(int r = 0; r < R; r++) {
            if(board[r][c] == 'X' && beginC == -1) {
                beginC = c;
            }
            if(board[r][c] == 'X') {
                endC = c + 1;
            }
        }
    }
}

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(board[r][c] != 'X') continue;

            int cnt = 0;
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr < 0 || nr >= R || nc < 0 || nc >= C || board[nr][nc] == '.') {
                    cnt++;
                }
            }

            if(cnt >= 3) {
                board[r][c] = '-'; // ??? ??
            }
        }
    }


    FindBeginRow();
    FindBeginCol();

    for(int r = beginR; r < endR; r++) {
        for(int c = beginC; c < endC; c++) {
            if(board[r][c] != 'X') {
                cout << '.';
            }else {
                cout << 'X';
            }
        }
        cout << '\n';
    }

}

