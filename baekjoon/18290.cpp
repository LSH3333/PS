#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int board[11][11];
bool selected[11][11];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int answer = -1000000000;

void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << selected[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

bool check(int r, int c) {
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if(selected[nr][nc]) return false;
    }
    return true;
}

void dfs(int idx, int sum, int cnt) {
    int r = idx / M;
    int c = idx % M;

    if(cnt == K) {
        answer = max(answer, sum);
        return;
    }
    if (idx >= N * M) {
        if(cnt == K) {
            answer = max(answer, sum);
        }
        return;
    }

    // ??
    if (check(r, c)) {
        selected[r][c] = true;
        dfs(idx + 1, sum + board[r][c], cnt + 1);
        selected[r][c] = false;
    }
    // ???? ??
    dfs(idx+1, sum, cnt);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, 0);

    cout << answer;
}