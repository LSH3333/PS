#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int board[3010][3010];
bool visited[3010][3010];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void MakeWall(int _r, int _c, int d) {
    board[_r][_c] = 1;
    int r = _r - d;
    int c = _c;

    while(r != _r) {
        if(r >= 1 && r <= N && c >= 1 && c <= M) {
            board[r][c] = 1;
        }
        r++; c++;
    }
    while(c != _c) {
        if(r >= 1 && r <= N && c >= 1 && c <= M) {
            board[r][c] = 1;
        }
        r++; c--;
    }
    while(r != _r) {
        if(r >= 1 && r <= N && c >= 1 && c <= M) {
            board[r][c] = 1;
        }
        r--; c--;
    }
    while(c != _c) {
        if(r >= 1 && r <= N && c >= 1 && c <= M) {
            board[r][c] = 1;
        }
        r--; c++;
    }
}

int bfs() {
    queue<pair<pair<int,int>,int>> q;
    visited[1][1] = true;
    q.push({{1, 1}, 0});

    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        if(r == N && c == M) {
            return depth;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 1 || nr > N || nc < 1 || nc > M) continue;
            if(board[nr][nc] == 1 || visited[nr][nc]) continue;
            q.push({{nr, nc}, depth + 1});
            visited[nr][nc] = true;
        }
    }
    return -1;
}

void Print() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << board[i][j] << ' ';
        } cout<< endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;

    for(int i = 0; i < K; i++) {
        int r, c, d; cin >> r >> c >> d;
        MakeWall(r, c, d);
    }


    int res = bfs();
    if(res == -1) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        cout << res;
    }
}