#include <iostream>
using namespace std;

char board[8][8][9];
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};

void MakeBoard() {
    for(int i = 1; i < 9; i++) {
        for(int r = 7; r > 0; r--) {
            for(int c = 0; c < 8; c++) {
                board[r][c][i] = board[r-1][c][i-1];
            }
        }
    }
}

void dfs(int r, int c, int depth) {
    int idx = depth > 8 ? 8 : depth;
    if(board[r][c][idx] == '#') return;

    if(r == 0 && c == 7) {
        cout << 1;
        exit(0);
    }

    for(int dir = 0; dir < 9; dir++) {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= 8 || nc < 0 || nc >= 8) continue;
        if(board[nr][nc][idx] == '#') continue;
        dfs(nr, nc, depth+1);
    }
}

int main() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> board[i][j][0];
        }
    }
    for(int i = 1; i < 9; i++) {
        for(int r = 0; r < 8; r++) {
            for(int c = 0; c < 8; c++) {
                board[r][c][i] = '.';
            }
        }
    }

    MakeBoard();
    dfs(7, 0, 0);
    cout << 0;
}