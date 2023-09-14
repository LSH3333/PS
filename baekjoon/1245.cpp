#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[101][71];
bool visited[101][71];
int dr[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

bool bfs(int _r, int _c) {
    bool isTop = true;
    queue<pair<int,int>> q;
    q.push({_r, _c});
    visited[_r][_c] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(board[nr][nc] > board[r][c]) isTop = false;
            if(visited[nr][nc] || board[nr][nc] != board[r][c]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    return isTop;
}


int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) visited[i][j] = true;
        }
    }

    int answer = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(visited[r][c]) continue;
            if(bfs(r,c)) {
                answer++;
            }
        }
    }


    cout << answer;

}