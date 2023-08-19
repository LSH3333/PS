#include <iostream>
#include <queue>
using namespace std;

int M, N, K;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs(int _r, int _c, vector<vector<bool>> &visited, vector<vector<int>> &board) {
    visited[_r][_c] = true;
    queue<pair<int,int>> q;
    q.push({_r, _c});

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(board[nr][nc] == 0 || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;

    while(T--) {
        int answer = 0;
        cin >> M >> N >> K;
        vector<vector<int>> board(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        for(int i = 0; i < K; i++) {
            int r, c; cin >> c >> r;
            board[r][c] = 1;
        }


        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(visited[i][j] || board[i][j] == 0) continue;
                bfs(i, j, visited, board);
                answer++;
            }
        }

        cout << answer << '\n';
    }

}