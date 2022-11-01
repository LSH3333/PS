#include <iostream>
#include <vector>
using namespace std;

int N, M;
char board[51][51];
int mark[51][51];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int r, int c, int depth, char color) {
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if(board[nr][nc] != color || mark[nr][nc] == 0) continue;
        if(abs(mark[nr][nc]-mark[r][c]) >= 3) {
            cout << "Yes"; exit(0);
        }
    }

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if(board[nr][nc] != color || mark[nr][nc] != 0) continue;
        mark[nr][nc] = depth+1;
        dfs(nr, nc, depth+1, color);
        mark[nr][nc] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0 ; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(mark[i][j] != 0) continue;
            mark[i][j] = 1;
            dfs(i, j, 1, board[i][j]);
        }
    }
    cout << "No";

}