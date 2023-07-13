#include <iostream>
using namespace std;

int N, M, answer;
bool visited[26];
char board[21][21];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void dfs(int r, int c, int depth) {

    answer = max(answer, depth);

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        char nextAlp = board[nr][nc];
        if(visited[int(nextAlp-'A')]) continue;
        visited[int(nextAlp-'A')] = true;
        dfs(nr, nc, depth+1);
        visited[int(nextAlp-'A')] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char c; cin >> c;
            board[i][j] = c;
        }
    }

    visited[int(board[0][0]-'A')] = true;
    dfs(0, 0, 1);

    cout << answer;

}