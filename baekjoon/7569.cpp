#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>

int M,N,H;
int tomato[101][101][101];
int mark[101][101][101];
int dh[6] = {0, 0, 0, 0, 1, -1};
int dr[6] = {-1, 0, 1, 0, 0, 0};
int dc[6] = {0, 1, 0, -1, 0, 0};

queue<vector<int>> q;
int idx = 1;

void print() {
    bool zero = false;
    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++) {
                ans = max(ans, mark[i][j][k]);
                if(mark[i][j][k] == 0) zero = true;
            }
        }
    }

    if(zero) cout << -1 << '\n';
    else cout << ans-1 << '\n';
}

void bfs() {

    while(!q.empty()) {
        int nh = q.front()[0];
        int nr = q.front()[1];
        int nc = q.front()[2];

        q.pop();
        if(mark[nh][nr][nc] > idx) idx++;

        for(int i = 0; i < 6; i++) {
            int nnh = nh + dh[i];
            int nnr = nr + dr[i];
            int nnc = nc + dc[i];

            if(nnr < 0 || nnr >= N || nnc < 0 || nnc >= M || nnh < 0 || nnh >= H) continue;
            if(tomato[nnh][nnr][nnc] == 0 && mark[nnh][nnr][nnc] == 0) {
                vector<int> vec = {nnh, nnr, nnc};
                q.push(vec);
                mark[nnh][nnr][nnc] = idx + 1;
            }
        }

    }
}

int main() {
    cin >> M >> N >> H;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++) {
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1) {
                    mark[i][j][k] = 1;
                    vector<int> vec = {i, j, k};
                    q.push(vec);
                }
                else if(tomato[i][j][k] == -1) mark[i][j][k] = -1;
            }
        }
    }

    bfs();

    print();



}