#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
char board[101][101];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void bfs(int _r, int _c, vector<vector<bool>> &visited) {
    queue<pair<int,int>> q;
    q.push({_r, _c});
    visited[_r][_c] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(visited[nr][nc] || board[nr][nc] != board[r][c]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // ?? ?? ??
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int cnt = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            if(visited[r][c]) continue;
            bfs(r, c, visited);
            cnt++;
        }
    }

    // ??? ??
    vector<vector<bool>> visited2(N, vector<bool>(N, false));
    int cnt2 = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            if(board[r][c] == 'G') {
                board[r][c] = 'R';
            }
        }
    }

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            if(visited2[r][c]) continue;
            bfs(r, c, visited2);
            cnt2++;
        }
    }

    cout << cnt << ' ' << cnt2;
}