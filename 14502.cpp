#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
char map[8][8];
char copy_map[8][8];
bool mark[8][8];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int ans = 0;


// 복사한 맵인 copy_map을 대상으로 바이러스가 퍼진 맵 만듦
void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r,c});
    mark[r][c] = true;

    while(!q.empty()) {
        int _r = q.front().first;
        int _c = q.front().second;
        q.pop();

        // 4방향으로 이동
        for(int i = 0; i < 4; i++) {
            int _dr = _r + dr[i];
            int _dc = _c + dc[i];
            // 맵 범위 벗어난다면 수행하지 않음
            if(_dr < 0 || _dr >= N || _dc < 0 || _dc >= M) continue;

            if((!mark[_dr][_dc]) && (copy_map[_dr][_dc] == '0')) {
                // 방문 표시
                mark[_dr][_dc] = true;
                copy_map[_dr][_dc] = '5'; // 바이러스 퍼진칸
                q.push({_dr, _dc});
            }
        }
    }

    // mark 초기화
    for(int i = 0; i < N; i++) {
        for(int j = 0; j  < M; j++) {
            mark[i][j] = false;
        }
    }
}


// bfs 탐색후 맵은 바뀌기 때문에
// 원본 연구실맵은 유지되어야 한다
void CopyMap() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            copy_map[i][j] = map[i][j];
        }
    }
}

// copy_map의 SafeZone 갯수를 리턴
int CountSafeZone() {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(copy_map[i][j] == '0') {
                cnt++;
            }
        }
    }

    return cnt;
}


void MakeWalls(int depth) {
    // 3개 벽 설치 완료
    if(depth == 3) {
        // bfs 탐색 이후 맵이 바뀌기 때문에 복사하고
        // 복사된 copy_map을 대상으로 bfs 탐색을 수행한다
        CopyMap();

        // copy_map에서 바이러스가 있는곳에서부터 bfs 탐색을 진행해 바이러스를 퍼트린다
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(copy_map[i][j] == '2') {
                    bfs(i,j);
                }
            }
        }

        // 안전영역을 최댓값으로 계속 갱신한다
        ans = max(ans, CountSafeZone());

        return;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // 비어있는 칸
            if(map[i][j] == '0') {
                // 벽 설치
                map[i][j] = '1';
                MakeWalls(depth+1);
                // 다음 벽 설치를 위해 다시 벽을 허문다
                map[i][j] = '0';
            }
        }
    }
}



int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }


    MakeWalls(0);

    cout << ans;

}