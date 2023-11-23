#include <iostream>
#include <queue>
using namespace std;

int N, M;
int before[31][31];
int after[31][31];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void bfs(int _r, int _c) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int,int>> q;
    visited[_r][_c] = true;
    q.push({_r, _c});
    int original = before[_r][_c], changed = after[_r][_c];
    before[_r][_c] = changed;

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (!visited[nr][nc] && before[nr][nc] == original) {
                visited[nr][nc] = true;
                before[nr][nc] = changed;
                q.push({nr, nc});
            }
        }
    }

}

void Determine() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (before[i][j] != after[i][j]) {
                bfs(i, j);
                return;
            }
        }
    }
}

bool Answer() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(before[i][j] != after[i][j]) return false;
        }
    }
    return true;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> before[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> after[i][j];
        }
    }

    Determine();

    if (Answer()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

}