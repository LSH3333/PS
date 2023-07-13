#include <iostream>
#include <queue>
using namespace std;

#define INF 100000000

int N, M;
char board[1010][1010];
int visited[1010][1010][2];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

struct Info {
    int r, c, wall;
};


void bfs() {
    queue<Info> q;
    visited[0][0][1] = 1;
    visited[0][0][0] = 1;
    q.push({0, 0, 1});

    while (!q.empty()) {
        int r = q.front().r, c = q.front().c;
        int wall = q.front().wall;
        q.pop();

        if(r == N-1 && c == M-1) {
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            if(board[nr][nc] == '0' && visited[nr][nc][wall] > visited[r][c][wall] + 1) {
                visited[nr][nc][wall] = visited[r][c][wall] + 1;
                q.push({nr, nc, wall});
            }
            if(board[nr][nc] == '1' && wall > 0 && visited[nr][nc][wall-1] > visited[r][c][wall] + 1) {
                visited[nr][nc][wall-1] = visited[r][c][wall] + 1;
                q.push({nr, nc, 0});
            }

        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            visited[i][j][0] = INF;
            visited[i][j][1] = INF;
        }
    }

    bfs();

    int answer = min(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1]);
    if(answer == INF) cout << -1;
    else cout << answer;
}