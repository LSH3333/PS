#include <iostream>
using namespace std;

int N, M, K;
int answer;
bool board[110][110];
bool mark[110][110];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int sum = 0;

void dfs(int r, int c) {
    mark[r][c] = true;
    sum++;
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr <= 0 || nr > N || nc <= 0 || nc > M) continue;
        if(!board[nr][nc] || mark[nr][nc]) continue;
        dfs(nr,nc);
    }
}

int main() {
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++) {
        int n, m;
        cin >> n >> m;
        board[n][m] = true;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(!board[i][j] || mark[i][j]) continue;
            dfs(i, j);
            answer = max(answer, sum);
            sum = 0;
        }
    }
    cout << answer;
}