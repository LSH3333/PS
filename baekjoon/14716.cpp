#include <iostream>
#include <queue>
using namespace std;

int R, C;
int board[251][251];
bool visited[251][251];
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int _r, int _c) {
    queue<pair<int,int>> q;
    q.push({_r, _c});
    visited[_r][_c] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(board[nr][nc] == 0 || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    int answer = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if (board[i][j] == 1 && !visited[i][j]) {
                bfs(i, j);
                answer++;
            }
        }
    }

    cout << answer;
}