#include <iostream>
using namespace std;
#include <algorithm>

int d[100001][3];
int score[2][100001];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> score[i][j];
            }
        }

        d[1][0] = 0; // 안떄어냄
        d[1][1] = score[0][1]; // 위를 때어냄
        d[1][2] = score[1][1]; // 아래를 때어냄

        for(int i = 2; i <= n; i++) {
            d[i][0] = max({d[i-1][0], d[i-1][1], d[i-1][2]});
            d[i][1] = max(d[i-1][2], d[i-1][0]) + score[0][i];
            d[i][2] = max(d[i-1][1], d[i-1][0]) + score[1][i];
        }

        cout << max({d[n][0], d[n][1], d[n][2]}) << '\n';

    }
}