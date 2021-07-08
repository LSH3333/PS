#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>

int M, N, K;
int cnt = 0;
int cab[51][51];
bool mark[51][51];
int dc[4] = {0, 1, 0, -1};
int dr[4] = {-1, 0, 1, 0};

void dfs(int r, int c) {
    if(mark[r][c] || cab[r][c] == 0) return;
    mark[r][c] = true;

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr > N || nc < 0 || nc > M) continue;

        dfs(nr, nc);
    }
}


void init() {
    cnt = 0;
    fill(&cab[0][0], &cab[51][51], 0);
    fill(&mark[0][0], &mark[51][51], false);
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        cin >> M >> N >> K;

        for(int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            cab[y][x] = 1;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(!mark[i][j] && cab[i][j] == 1) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
        init();
    }

}