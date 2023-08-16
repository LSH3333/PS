#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 100000000
int board[1010][1010];
int d[1010][1010];
int N, M;
int goalR, goalC;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void Find(int _r, int _c) {
    queue<pair<int,int>> q;
    q.push({_r, _c});

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(board[nr][nc] == 0) continue;
            int nextDist = d[r][c] + 1;
            if(d[nr][nc] <= nextDist) continue;

            q.push({nr, nc});
            d[nr][nc] = nextDist;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];

            if(board[i][j] == 2) {
                d[i][j] = 0;
                goalR = i; goalC = j;
            } else {
                d[i][j] = INF;
            }
        }
    }

    Find(goalR, goalC);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // ?? ? ? ?? ?
            if(board[i][j] == 0) {
                cout << 0 << ' ';
            }
                // ?? ? ? ?? ??? ?? ??
            else if(board[i][j] > 0 && d[i][j] == INF) {
                cout << -1 << ' ';
            }
            else {
                cout << d[i][j] << ' ';
            }
        } cout << '\n';
    }
}