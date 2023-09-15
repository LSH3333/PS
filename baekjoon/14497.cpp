#include <iostream>
#include <queue>
using namespace std;

int N, M, answer;
char board[301][301];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};


void Print() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << board[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

bool bfs(int _r, int _c) {
    vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));
    queue<pair<int,int>> q;
    q.push({_r, _c});
    visited[_r][_c] = true;

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 1 || nr > N || nc < 1 || nc > M || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            if(board[nr][nc] == '0') {
                q.push({nr, nc});
            }
                // ???? ??('1')?? '0' ?? ??? ??? ?? ???
            else if (board[nr][nc] == '1') {
                board[nr][nc] = '0';
            }
            else if(board[nr][nc] == '#') {
                return true;
            }
        }
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int r1,c1,r2,c2;
    cin >> N >> M;
    cin >> r1 >> c1 >> r2 >> c2;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    while(true) {
        bool res = bfs(r1, c1);
        answer++;
        if(res) break;
    }

    cout << answer;
}