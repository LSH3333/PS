#include <iostream>
#include <queue>
using namespace std;

int N, M;
char board[601][601];
bool visited[601][601];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

int bfs(int _r, int _c) {
    int answer = 0;
    queue<pair<int,int>> q;
    q.push({_r, _c});
    visited[_r][_c] = true;

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        if (board[r][c] == 'P') {
            answer++;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(board[nr][nc] == 'X' || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int _r , _c;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'I') {
                _r = i; _c = j;
                board[i][j] = 'X';
            }
        }
    }

    int answer = bfs(_r, _c);
    if(answer == 0) {
        cout << "TT";
    } else {
        cout << answer;
    }
}