#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, K;
char board[6][6];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool visited[6][6];
int answer;

void dfs(int r, int c, int depth) {

    if(r == 0 && c == C - 1) {
        if(depth == K) answer++;
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if(board[nr][nc] == 'T' || visited[nr][nc]) continue;
        visited[nr][nc] = true;
        dfs(nr, nc, depth + 1);
        visited[nr][nc] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C >> K;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    visited[R-1][0] = true;
    dfs(R - 1, 0, 1);

    cout << answer;

}