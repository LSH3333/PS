#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int maxHeight;
int map[101][101]; // 원본
int copied_map[101][101];
bool mark[101][101];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int safeZone = 0;

void CopyMap() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            copied_map[i][j] = map[i][j];
        }
    }
}

void bfs(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r,c});
    mark[r][c] = true;

    copied_map[r][c] = -2; // bfs 확인용

    while(!q.empty()) {
        int _r = q.front().first;
        int _c = q.front().second;
        q.pop();

        // 동서남북 4방향 탐색
        for(int i = 0; i < 4; i++) {
            int nr = _r + dr[i];
            int nc = _c + dc[i];

            // 범위 벗어나면 수행하지 않음
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            // 방문하지 않은곳 && 물에 잠기지 않은곳에 대해서만 수행
            if(!mark[nr][nc] && copied_map[nr][nc] > 0) {
                q.push({nr,nc});
                mark[nr][nc] = true;

                copied_map[nr][nc] = -2;
            }

        }
    }

    // 방문여부 mark 초기화
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            mark[i][j] = false;
        }
    }
}

// height 만큼 비를 내려본다
void Flood(int height) {
    CopyMap();

    // height보다 낮은 지역에 비를 내린다
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            // height보다 낮은 지역은 물에잠긴다
            if(copied_map[i][j] <= height) {
                copied_map[i][j] = -1; // 물에 잠김
            }
        }
    }

    // 현재 copied_map의 안전영역의 수 확인
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(copied_map[i][j] > 0) {
                cnt++;
                bfs(i,j);
            }
        }
    }

    // 안전영역수의 최댓값 갱신
    safeZone = max(safeZone, cnt);

}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int num;
            cin >> num;
            map[i][j] = num;

            maxHeight = max(maxHeight, num);
        }
    }

    // 0부터 maxHeight-1 까지 비를 내려본다 (모든 경우의 수 확인)
    // maxHeight만큼 비가 내리면 어처피 모든 지역이 물에 잠기기때문에 확인하지 않아도된다
    for(int i = 0; i < maxHeight; i++) {
        Flood(i);
    }

    cout << safeZone;

}
