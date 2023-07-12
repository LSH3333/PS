#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int M,N,K;
int board[101][101];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};


void MakeSquare(int r1, int c1, int r2, int c2) {
    for(int r = r1; r < r2; r++) {
        for(int c = c1; c < c2; c++) {
            board[r][c] = 1;
        }
    }
}

int bfs(int _r, int _c) {
    int cnt = 0;
    queue<pair<int,int>> q;
    board[_r][_c] = 2;
    q.push({_r, _c});

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        cnt++;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(board[nr][nc] != 0) continue;
            q.push({nr, nc});
            board[nr][nc] = 2;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> answers;
    cin >> M >> N >> K;
    for(int i = 0; i < K; i++) {
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        MakeSquare(r1,c1,r2,c2);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] != 0) continue;
            int res = bfs(i,j);
            answers.push_back(res);
        }
    }

    sort(answers.begin(), answers.end());
    cout << answers.size() << '\n';
    for(auto x : answers) cout << x << ' ';

}