#include <iostream>
using namespace std;

int N, M;
int board[1030][1030];
int sums[1030][1030];

int GetSum(int r, int c) {
    return sums[r - 1][c] + sums[r][c - 1] - sums[r - 1][c - 1] + board[r][c];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    // sums array
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sums[i][j] = GetSum(i, j);
        }
    }

    for(int i = 0; i < M; i++) {
        int r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2;
        int ans = sums[r2][c2] - sums[r1-1][c2] - sums[r2][c1-1] + sums[r1-1][c1-1];
        cout << ans << '\n';
    }
}