#include <iostream>
#include <queue>
using namespace std;

#define INF 100000
int N, M;
char b[51][51];
int d[2][51][51];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};


int CountGarbageNearBy(int r, int c) {
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if(b[nr][nc] == 'g') {
            cnt++;
        }
    }
    return cnt;
}

void bfs(int sr, int sc) {
    queue<pair<int,int>> q;
    q.push({sr, sc});
    d[0][sr][sc] = 0;
    d[1][sr][sc] = 0;

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            // ??? ??
            if (b[nr][nc] == '.') {
                // ???? ??? ???? ?? ??
                if(CountGarbageNearBy(nr,nc) > 0) {
                    if((d[0][r][c] < d[0][nr][nc]) ||
                       (d[0][r][c] == d[0][nr][nc] && d[1][r][c]+1 < d[1][nr][nc])) {
                        q.push({nr, nc});
                        d[0][nr][nc] = d[0][r][c];
                        d[1][nr][nc] = d[1][r][c]+1;
                    }
                }
                else {
                    // ???? ??? ?? ??? ?? ?? ||
                    // ???? ???? ??? ??? ??? ????? ??? ??? ??
                    if((d[0][r][c] < d[0][nr][nc]) ||
                       (d[0][r][c] == d[0][nr][nc] && d[1][r][c] < d[1][nr][nc])) {
                        q.push({nr, nc});
                        d[0][nr][nc] = d[0][r][c];
                        d[1][nr][nc] = d[1][r][c];
                    }
                }
            }
                // ??? ???
            else if (b[nr][nc] == 'g') {
                if((d[0][r][c]+1 < d[0][nr][nc]) ||
                   (d[0][r][c]+1 == d[0][nr][nc] && d[1][r][c] < d[1][nr][nc])) {
                    q.push({nr, nc});
                    d[0][nr][nc] = d[0][r][c] + 1;
                    d[1][nr][nc] = d[1][r][c];
                }
            }
                // ??? ????
            else if (b[nr][nc] == 'F') {
                // ?? ??? ??
                if((d[0][r][c] < d[0][nr][nc]) ||
                   (d[0][r][c] == d[0][nr][nc] && d[1][r][c] < d[1][nr][nc])) {
                    d[0][nr][nc] = d[0][r][c];
                    d[1][nr][nc] = d[1][r][c];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int sr, sc, gr, gc;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> b[i][j];
            if(b[i][j] == 'S') {
                sr = i; sc = j;
            } else if (b[i][j] == 'F') {
                gr = i; gc = j;
            }
            d[0][i][j] = INF;
            d[1][i][j] = INF;
        }
    }


    bfs(sr,sc);


    cout << d[0][gr][gc] << ' ' << d[1][gr][gc];

}