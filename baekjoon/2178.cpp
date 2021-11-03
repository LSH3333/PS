#include <iostream>
#include <queue>
using namespace std;
#include <utility>

int arr[101][101];
int mark[101][101];
int H,W;
int index = 1;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};


void bfs(int r, int c) {
    queue<pair<int,int>> q;

    mark[r][c] = index;
    q.push(make_pair(r,c));

    while(!q.empty()) {
        int nr = q.front().first;
        int nc = q.front().second;
        q.pop();
        if(mark[nr][nc] > index) index++; // 현재 정점의 마킹이 인덱스값보다 크면 인덱스값 증가

        for(int i = 0; i < 4; i++) {
            int nnr = nr + dr[i];
            int nnc = nc + dc[i];

            if(nnr < 0 || nnr >= H || nnc < 0 || nnc >= W) continue;
            if(arr[nnr][nnc] == 1 && mark[nnr][nnc] == 0) {
                q.push(make_pair(nnr, nnc)); // 현재 정점 주위 정점을 q에 push
                mark[nnr][nnc] = index + 1;  // 이때 index + 1 을 마킹
            }

        }

    }

}

int main() {
    cin >> H >> W;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    bfs(0,0);

    cout << mark[H-1][W-1] << endl;
}