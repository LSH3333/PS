#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 10000000
int N, M, HR, HC, ER, EC;
char board[1010][1010];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

struct Data {
    int r, c;
    bool chance;
};

int visited[2][1010][1010];

bool bfs() {
    queue<Data> q;
    q.push({HR, HC, true});
    visited[true][HR][HC] = 0;

    while (!q.empty()) {
        int r = q.front().r, c = q.front().c;
        bool chance = q.front().chance;
        q.pop();

        if(r == ER && c == EC) {
            return true;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr <= 0 || nr > N || nc <= 0 || nc > M) continue;
            if (board[nr][nc] == '0') {
                if(visited[chance][nr][nc] > visited[chance][r][c] + 1) {
                    visited[chance][nr][nc] = visited[chance][r][c] + 1;
                    q.push({nr, nc, chance});
                }
            }
            else {
                if (chance && visited[0][nr][nc] > visited[chance][r][c] + 1) {
                    visited[0][nr][nc] = visited[chance][r][c] + 1;
                    q.push({nr, nc, false});
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> HR >> HC >> ER >> EC;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> board[i][j];
            visited[0][i][j] = INF;
            visited[1][i][j] = INF;
        }
    }

    if (bfs()) {
        cout << min(visited[0][ER][EC], visited[1][ER][EC]);
    } else {
        cout << -1;
    }
}