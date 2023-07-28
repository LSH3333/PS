#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N, M;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0,1,0,-1};

int bfs(char goal, int _r, int _c, const vector<string> &maps) {
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    q.push({{_r, _c}, 0});
    visited[_r][_c] = true;

    while (!q.empty()) {
        int r = q.front().first.first, c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        if(maps[r][c] == goal) {
            return depth;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(visited[nr][nc] || maps[nr][nc] == 'X') continue;
            visited[nr][nc] = true;
            q.push({{nr, nc}, depth + 1});
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    N = (int)maps.size();
    M = (int) maps.front().size();

    int sr, sc, lr, lc;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(maps[i][j] == 'S') {
                sr = i; sc = j;
            } else if (maps[i][j] == 'L') {
                lr = i; lc = j;
            }
        }
    }

    int cnt = bfs('L', sr, sc, maps);
    int cnt2 = bfs('E', lr, lc, maps);

    if(cnt != -1 && cnt2 != -1) {
        answer = cnt + cnt2;
    } else {
        answer = -1;
    }

    return answer;
}

int main() {
    vector<string> maps = {
            "LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"
    };

    solution(maps);
}