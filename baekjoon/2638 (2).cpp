#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[101][101];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

int bfs(int _r, int _c) {
    int removeCnt = 0;
    vector<vector<int>> visited(N + 1, vector<int>(M + 1, 0));
    queue<pair<int,int>> q;
    visited[_r][_c] = 1;
    q.push({_r, _c});

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            // ??? ??
            if(board[nr][nc] == 1) {
                visited[nr][nc]++;
            }
                // ??? ? ??
            else {
                if(visited[nr][nc] == 0) {
                    visited[nr][nc]++;
                    q.push({nr, nc});
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // ????? ? ?? ??? = ?? ??
            if(visited[i][j] >= 2 && board[i][j] == 1) {
                board[i][j] = 0;
                removeCnt++;
            }
        }
    }

    return removeCnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }


    int answer = 0;
    while(true) {
        int removeCnt = bfs(0,0);
        if(removeCnt == 0) break;
        answer++;
    }

    cout << answer;
}