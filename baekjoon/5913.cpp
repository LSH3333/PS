#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;
bool board[6][6];
bool visited[6][6];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int answer;


void dfs(int r, int c, int cnt) {
    if(r == 5 && c == 5) {
        if(cnt == 25-K) {
            answer++;
        }
        return;
    }
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr < 1 || nr > 5 || nc < 1 || nc > 5) continue;
        if(board[nr][nc] || visited[nr][nc]) continue;
        visited[nr][nc] = true;
        dfs(nr, nc, cnt + 1);
        visited[nr][nc] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> K;
    for(int i = 0; i < K; i++) {
        int r,c; cin >> r >> c;
        board[r][c] = true;
    }

    visited[1][1] = true;
    dfs(1, 1, 1);

    cout << answer;
}