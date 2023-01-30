#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int W, H;
bool visited[21][21];
char board[21][21];
int mark[12][12]; // i 부터 j 까지 최단 거리 저장
int answer;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(int beginR, int beginC, int goalR, int goalC) {
    queue<pair<pair<int,int>,int>> q;
    q.push({{beginR, beginC}, 0});
    memset(visited, false, sizeof(visited));

    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if(nr == goalR && nc == goalC) {
                return depth+1;
            }
            if(visited[nr][nc] || board[nr][nc] == 'x') continue;
            q.push({{nr, nc}, depth + 1});
            visited[nr][nc] = true;
        }
    }
    return -1;
}

int Cal(const vector<int> &order, const vector<pair<int,int>> &dust) {
    int beginIdx = 0;
    int totalDist = 0;

    for(int i = 0; i < order.size(); i++) {
        int goalIdx = order[i];
        int dist = mark[beginIdx][goalIdx];
        if(dist == -1) return -1;
        totalDist += dist;
        beginIdx = goalIdx;
    }
    return totalDist;
}

// i 부터 j 까지 최단거리 저장해놓음
void CalDustToDust(const vector<pair<int,int>> &dust) {
    for(int i = 0; i < dust.size(); i++) {
        for(int j = i+1; j < dust.size(); j++) {
            int beginR = dust[i].first, beginC = dust[i].second;
            int goalR = dust[j].first, goalC = dust[j].second;
            int dist = bfs(beginR, beginC, goalR, goalC);
            mark[i][j] = dist;
            mark[j][i] = dist;
        }
    }
}

void Init() {
    memset(mark, 0, sizeof(mark));
    answer = 10000000;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(true) {
        cin >> W >> H;
        if(W == 0 && H == 0) break;
        Init();

        // [0] = 로봇 위치
        vector<pair<int, int>> dust = {{0,0}};
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cin >> board[i][j];
                if(board[i][j] == '*') dust.push_back({i, j});
                else if(board[i][j] == 'o') {
                    dust[0] = {i, j};
                }
            }
        }

        CalDustToDust(dust);

        vector<int> order;
        for(int i = 1; i <= dust.size()-1; i++) {
            order.push_back(i);
        }


        do {
            int ret = Cal(order, dust);
            if(ret != -1) {
                answer = min(answer, ret);
            }
        } while (next_permutation(order.begin(), order.end()));

        if(answer == 10000000) cout << -1 << '\n';
        else cout << answer << '\n';
    }


}