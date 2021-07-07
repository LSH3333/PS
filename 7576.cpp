#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#include <algorithm>

int M,N;
int idx = 1;
int tomato[1001][1001] = {0,};
int mark[1001][1001] = {0, };
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
queue<pair<int,int>> q;

void bfs() {

    while(!q.empty()) {
        int nr = q.front().first;
        int nc = q.front().second;
        q.pop();
        if(mark[nr][nc] > idx) idx++;

        for(int i = 0; i < 4; i++) {
            int nnr = nr + dr[i];
            int nnc = nc + dc[i];

            if(nnr < 0 || nnr >= N || nnc < 0 || nnc >= M) continue;
            if(tomato[nnr][nnc] == 0 && mark[nnr][nnc] == 0) {

                q.push(make_pair(nnr, nnc));
                mark[nnr][nnc] = idx + 1;
            }

        }
    }
}

int main() {
    cin >> M >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> tomato[i][j];
            if(tomato[i][j] == 1) {
                q.push(make_pair(i,j));
                mark[i][j] = 1;
            }
            else if(tomato[i][j] == -1) {
                mark[i][j] = -1;
            }
        }
    }


    bfs();

    int ans = 0;
    bool zero = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            ans = max(ans, mark[i][j]);
            if(mark[i][j] == 0) zero = true;
        }
    }

    if(zero) cout << -1 << '\n';
    else cout << ans - 1 << '\n';



}