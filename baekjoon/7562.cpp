#include <iostream>
using namespace std;
#include <queue>
#define MAX 301

int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int mark[MAX][MAX];
int l, idx=0;

void init() {
    fill(&mark[0][0], &mark[MAX-1][MAX-1], 0);
    idx = 0;
}

int bfs(int r, int c, int dest_r, int dest_c) {
    queue<pair<int,int>> q;
    q.push({r,c});
    mark[r][c] = idx;

    while(!q.empty()) {
        int nr = q.front().first;
        int nc = q.front().second;
        q.pop();
        if(mark[nr][nc] > idx) idx++;

        if(nr == dest_r && nc == dest_c) {
            return idx;
        }

        for(int i = 0; i < 8; i++) {
            int nnr = nr + dr[i];
            int nnc = nc + dc[i];

            if(nnr < 0 || nnr >= l || nnc < 0 || nnc >= l) continue;

            if(mark[nnr][nnc] == 0) {
                q.push({nnr,nnc});
                mark[nnr][nnc] = idx + 1;
            }
        }

    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        /* 출발지점 */
        int r,c;
        /* 도착지점 */
        int dest_r, dest_c;
        cin >> l;
        cin >> r >> c;
        cin >> dest_r >> dest_c;


        cout << bfs(r,c,dest_r,dest_c) << '\n';
        init();
    }




}