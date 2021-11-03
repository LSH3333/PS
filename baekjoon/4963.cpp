#include <iostream>
using namespace std;
#include <cstring>

int island[51][51];
int mark[51][51];
int drow[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dcol[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int island_idx = 1;
int w=1, h=1;

void dfs(int row, int col) {
    if(island[row][col] == 0 || mark[row][col] > 0) return;
    mark[row][col] = island_idx;

    for(int i = 0; i < 8; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow < 0 || nrow > h || ncol < 0 || ncol > w) continue;
        dfs(nrow, ncol);

        /*if(0 <= ncol && ncol < w && 0 <= nrow && nrow < h) {
            dfs(nrow, ncol);
        }*/
    }

}

void init() {
    memset(island, 0, sizeof(island));
    memset(mark, 0, sizeof(mark));
    island_idx = 1;
}

int main() {
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> island[i][j];
            }
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(island[i][j] > 0 && mark[i][j] == 0) {
                    dfs(i, j);
                    island_idx++;
                }
            }
        }

        cout << island_idx-1 << endl;

        init();
    }

}