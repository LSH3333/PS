#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define INF 100000000

int N, M, T;
int board[101][101];
bool visited[101][101];
int answer;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

// 시작지점 에서 도착지점 까지 걸리는 시간 리턴
int MoveToGoal(int startR, int startC, int goalR, int goalC, bool sword) {
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int,int>,int>> q;
    visited[startR][startC] = true;
    q.push({{startR, startC}, 0});

    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        // 공주 에게 도착
        if(r == goalR && c == goalC) {
            return depth;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(!sword && board[nr][nc] == 1) continue;
            if(visited[nr][nc]) continue;
            q.push({{nr, nc}, depth + 1});
            visited[nr][nc] = true;
        }
    }

    return INF;
}



int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int swordR, swordC;
    cin >> N >> M >> T;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) {
                swordR = i; swordC = j;
            }
        }
    }

    int startToPrincess = MoveToGoal(0, 0, N - 1, M - 1, false);
    int startToSword = MoveToGoal(0, 0, swordR, swordC, false);
    int swordToPrincess = MoveToGoal(swordR, swordC, N-1, M-1, true);


    answer = min(startToPrincess, startToSword + swordToPrincess);
    if(answer <= T) cout << answer;
    else cout << "Fail";
}