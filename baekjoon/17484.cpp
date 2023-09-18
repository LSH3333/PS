#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[7][7];
int dc[] = {-1, 0, 1};
int answer = 10000;

void dfs(int r, int c, vector<int> &used, int res) {
    if(r == N) {
        answer = min(answer, res);
        return;
    }

    res = res + arr[r][c];

    for(int i = 0; i < 3; i++) {
        int nr = r + 1, nc = c + dc[i];
        if(nc < 0 || nc >= M) continue;
        if(r-1 >= 0 && i == used[r-1]) continue;
        used[r] = i;
        dfs(nr, nc, used, res);
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for(int c = 0; c < M; c++) {
        vector<int> used(N+1, -1);
        dfs(0, c, used, 0);
    }

    cout << answer;
}