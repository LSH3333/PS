#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

bool bfs(int _r, int _c, const vector<string> &place) {
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    queue<pair<int,pair<int,int>>> q;
    visited[_r][_c] = true;
    q.push({0, {_r, _c}});

    while (!q.empty()) {
        int depth = q.front().first;
        int r = q.front().second.first, c = q.front().second.second;
        q.pop();
        if(depth == 2) continue;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
            if(visited[nr][nc]) continue;
            if(place[nr][nc] == 'P') return false;
            if (place[nr][nc] == 'O') {
                visited[nr][nc] = true;
                q.push({depth + 1, {nr, nc}});
            }
        }
    }
    return true;
}

bool CheckPlace(const vector<string> &place) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if (place[i][j] == 'P') {
                if (!bfs(i, j, place)) {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (const auto &place: places) {
        if(CheckPlace(place)) {
            answer.push_back(1);
        } else {
            answer.push_back(0);
        }
    }

    return answer;
}

int main() {
    vector<vector<string>> places = {
            {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
            {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
            {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
            {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
            {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };
    solution(places);
}