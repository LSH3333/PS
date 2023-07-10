#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, answer;
int board[10][10];
vector<pair<int,int>> virus;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void Print() {
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            cout << board[r][c] << ' ';
        } cout << endl;
    } cout << endl;
}

int CheckSafe(const vector<vector<bool>> &visited) {
    int safeCnt = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(board[r][c] == 0 && !visited[r][c]) {
                safeCnt++;
            }
        }
    }
    return safeCnt;
}

void SpreadVirus() {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int,int>> q;
    for(auto x : virus) {
        q.push({x.first, x.second});
        visited[x.first][x.second] = true;
    }

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(board[nr][nc] != 0 || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    int res = CheckSafe(visited);
    if(res > 0) answer = max(answer, res);
}



void dfs(int depth, int _r, int _c) {
    if(depth == 3) {
        SpreadVirus();
//        Print();
        return;
    }
//    cout << "_r,_c : " << _r << ',' << _c << endl;
    for(int r = _r; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(board[r][c] != 0) continue;
//            cout << "r,c : " << r << ',' << c << endl;
            board[r][c] = 3;

            int nr = r, nc = c + 1;
            if(nc >= M) {nr++; nc=0;}
            dfs(depth+1, nr, nc);
            board[r][c] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    dfs(0, 0, 0);

    cout << answer;
}