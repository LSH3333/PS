#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000
int R,C;
char board[MAX+1][MAX+1];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void bfs() {
    queue<pair<int,int>> q;
    for(int c = 0; c < C; c++) {
        if(board[0][c] == '0') {
            q.push({0, c});
        }
    }

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(board[nr][nc] != '0') continue;
            board[nr][nc] = '2';
            q.push({nr, nc});
        }
    }
}

bool isPossible() {
    for(int c = 0; c < C; c++) {
        if(board[R-1][c] == '2') {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    bfs();

    bool res = isPossible();
    if(res) cout << "YES";
    else cout << "NO";
}