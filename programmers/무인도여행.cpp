#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool visited[110][110];

int bfs(int _r, int _c, const vector<string> &maps) {
    int sum = 0;
    queue<pair<int,int>> q;
    visited[_r][_c] = true;
    q.push({_r, _c});

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        sum += int(maps[r][c] - '0');

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(visited[nr][nc] || maps[nr][nc] == 'X') continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    N = (int)maps.size();
    M = (int)maps.front().size();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(maps[i][j] == 'X' || visited[i][j]) continue;
            int res = bfs(i, j, maps);
            answer.push_back(res);
        }
    }

    sort(answer.begin(), answer.end());

    if(answer.empty()) {
        answer.push_back(-1);
    }

    return answer;
}

int main() {
    vector<string> maps = {"XXX","XXX","XXX"};
    solution(maps);
}