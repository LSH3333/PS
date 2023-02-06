#include <iostream>
#include <queue>
using namespace std;

int N, M;
char board[110][110];
bool visited[110][110];
int whiteScore, blueScore;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(int _r, int _c) {
    int score = 1;
    queue<pair<int,int>> q;
    visited[_r][_c] = true;
    q.push({_r, _c});

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(visited[nr][nc] || board[nr][nc] != board[_r][_c]) continue;
            score++;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    return score * score;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j]) continue;
            if(board[i][j] == 'W') whiteScore += bfs(i, j);
            else blueScore += bfs(i, j);
        }
    }

    cout << whiteScore << ' ' << blueScore;
}