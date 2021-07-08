#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001
#include <cstdio>

int N, M;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
char map[MAX][MAX];
int mark[MAX][MAX][2];
int idx = 1;

int bfs() {
    // {r,c}, 부실수 있는 벽 횟수
    queue<pair<pair<int,int>, int>> q;
    // {1,1}에서 시작, 벽 1번 부술수 있음
    q.push({{1,1},1});
    mark[1][1][1] = 1;

    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int wall = q.front().second;
        q.pop();

        if(mark[r][c][wall] > idx) idx++;

        if(r == N && c == M) {
            return mark[r][c][wall];
        }

        // 4방향으로 탐색
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 맵 벗어나면 실행안함
            if(nr < 1 || nr > N || nc < 1 || nc > M) continue;

            // 갈수있는 길이고, 방문하지 않았다면
            if(map[nr][nc] == '0' && mark[nr][nc][wall] == 0) {
                q.push({{nr,nc}, wall}); // 갈수있는 길이므로 wall안부숴도 됨
                mark[nr][nc][wall] = idx+1;
            }
            // 갈수없는 길이고, 벽을 뚫을수 있는 기회가 남았다면
            if(map[nr][nc] == '1' && wall) {
                mark[nr][nc][wall-1] = idx+1;
                // 벽을 뚫었으므로 벽을 뚫을수있는 기회가 소진됨. wall-1
                q.push({{nr,nc},wall-1});
            }

        }

    }
    return -1;
}

void print() {
    for(int re = 0; re < 2; re++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                cout << mark[i][j][re] << ' ';
            } cout << '\n';
        }    cout << '\n\n';
    }

}

int main() {

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        scanf("%s", &map[i][1]);
    }

    cout << bfs();
}