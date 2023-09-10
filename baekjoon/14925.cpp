#include <iostream>
using namespace std;

int R, C, answer;
int d[1002][1002];
int a[1002][1002];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            if(a[i][j] != 0) continue;
            d[i][j] = min(min(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + 1;
            answer = max(answer, d[i][j]);
        }
    }

    cout << answer;
}