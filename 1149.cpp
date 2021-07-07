#include <iostream>
using namespace std;
#include <algorithm>

int rgb[1001][3];
int d[1001][3];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> rgb[i][j];
        }
    }
    // d[1]은 첫번째 집이므로 rgb값 그대로
    d[1][0] = rgb[1][0];
    d[1][1] = rgb[1][1];
    d[1][2] = rgb[1][2];

    // bottom - up
    for(int i = 2; i <= n; i++) {
        d[i][0] = min(d[i-1][1], d[i-1][2]) + rgb[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + rgb[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + rgb[i][2];
    }

    // d[n][0] ~ d[n][2] 중 최솟값이 답
    cout << min({d[n][0], d[n][1], d[n][2]}) << '\n';
}