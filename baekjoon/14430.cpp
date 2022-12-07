#include <iostream>
using namespace std;

int N, M;
int a[310][310];
int d[310][310];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            d[i][j] = a[i][j] + max(d[i - 1][j], d[i][j - 1]);
        }
    }

    cout << d[N][M];
}