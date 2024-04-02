#include <iostream>
using namespace std;

#define MAX 500
int R, C;
int board[MAX + 1][MAX + 1];
int d[MAX + 1][MAX + 1][2];
int result[MAX + 1][MAX + 1];
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

pair<int,int> dfs(int r, int c) {
    if(d[r][c][0] != -1 && d[r][c][1] != -1) {
        return {d[r][c][0], d[r][c][1]};
    }

    // find minVal
    int minVal = 400000;
    for(int i = 0; i < 8; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        minVal = min(minVal, board[nr][nc]);
    }

    // ?? ??
    if (board[r][c] < minVal) {
        return {r, c};
    }

    // ?? ?? ??
    int minNR=0, minNC=0;
    for(int i = 0; i < 8; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if (board[nr][nc] == minVal) {
            minNR = nr;
            minNC = nc;
            break;
        }
    }

    return dfs(minNR, minNC);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
            d[i][j][0] = -1;
            d[i][j][1] = -1;
        }
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            pair<int, int> res = dfs(i, j);
            result[res.first][res.second]++;
            d[i][j][0] = res.first;
            d[i][j][1] = res.second;
        }
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << result[i][j] << ' ';
        } cout << '\n';
    }
}