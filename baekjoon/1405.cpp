#include <iostream>
#include <vector>
using namespace std;

int N;
double perc[4];
bool mark[50][50];

// e, w, s, n
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

double ans;

void dfs(int depth, int r, int c, double res) {
    if(depth == N) {
        ans += res;
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(mark[nr][nc]) continue;
        mark[nr][nc] = true;
        dfs(depth+1, nr, nc, res * perc[i]);
        mark[nr][nc] = false;
    }
}

int main() {
    cin >> N;
    cin >> perc[0] >> perc[1] >> perc[2] >> perc[3];
    for(int i = 0; i < 4; i++) {
        if(perc[i] == 0) continue;
        perc[i] /= 100;
    }

    mark[25][25] = true;
    dfs(0, 25, 25, 1);
    cout.precision(11); cout << fixed;
    cout << ans;
}
