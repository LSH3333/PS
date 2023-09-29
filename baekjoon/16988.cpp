#include <iostream>
#include <queue>
using namespace std;

int N, M, answer;
int board[21][21];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << board[i][j] << ' ';
        }cout<<endl;
    }cout<<endl;
}

int bfs(int _r, int _c, vector<vector<bool>> &visited) {
    bool surround = true;
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({_r, _c});
    visited[_r][_c] = true;

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        cnt++;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            // ????? ??
            if(board[nr][nc] == 0) {
                surround = false;
//                return 0;
            }
            else if(board[nr][nc] == 2 && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    if(surround) {
        return 0;
    }
    return cnt;
}

int FindCnt() {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int cnt = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(board[r][c] == 2 && !visited[r][c]) {
                cout << "r,c: " << r << ',' << c << endl;
                int res = bfs(r, c, visited);
                cout << "res: " << res << endl;
                cnt += res;
            }
        }
    }
    return cnt;
}

void PutMyStones(int loc, int depth) {
    if(depth == 2){
        Print();
        int cnt = FindCnt();
        answer = max(answer, cnt);
        cout << cnt << endl;
        return;
    }

    for(int i = loc; i < N*M; i++) {
        int r = i / M, c = i % M;
        if(board[r][c] == 0) {
            board[r][c] = 1;
            PutMyStones(i+1, depth+1);
            board[r][c] = 0;
        }
    }

}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    PutMyStones(0, 0);

    cout << answer;
}