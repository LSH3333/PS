#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[510][510];
bool visited[510][510];
int ansCnt, ansWidth;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(int _r, int _c) {
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({_r, _c});
    visited[_r][_c] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        cnt++;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(visited[nr][nc] || board[nr][nc] == 0) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 0 || visited[i][j]) continue;
            int ret = bfs(i, j);
            ansCnt++;
            ansWidth = max(ansWidth, ret);
        }
    }

    cout << ansCnt << '\n' << ansWidth;
}