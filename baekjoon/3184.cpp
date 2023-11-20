#include <iostream>
#include <queue>
using namespace std;

int R, C;
int totalSheep, totalWolf;
char board[251][251];
bool visited[251][251];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void bfs(int _r, int _c) {
    int sheep = 0, wolf = 0;
    queue<pair<int,int>> q;
    q.push({_r, _c});
    visited[_r][_c] = true;

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        if (board[r][c] == 'o') {
            sheep++;
        } else if (board[r][c] == 'v') {
            wolf++;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(visited[nr][nc] || board[nr][nc] == '#') continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    // ??? ??
    if(sheep <= wolf) {
        totalSheep-=sheep;
    }
        // ?? ??
    else {
        totalWolf-=wolf;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'o') {
                totalSheep++;
            } else if(board[i][j] == 'v') {
                totalWolf++;
            }
        }
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(visited[i][j]) continue;
            if (board[i][j] == 'o') {
                bfs(i, j);
            }
        }
    }

    cout << totalSheep << ' ' << totalWolf;
}