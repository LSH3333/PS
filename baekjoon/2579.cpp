#include <iostream>
using namespace std;

int stairs[301];
int d[301][2];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }

    // d[n][0] : n번째 계단을 올랐을때, 1칸을 오름, 그때의 총 점수의 최대값
    // d[n][1] : n번째 계단을 올랐을때, 2칸을 오름, 그때의 총 점수의 최대값
    d[1][0] = stairs[1];
    d[1][1] = stairs[1];
    d[2][0] = d[1][0] + stairs[2];
    d[2][1] = stairs[2];

    for(int i = 3; i <= n; i++) {
        d[i][0] = d[i-1][1] + stairs[i];
        d[i][1] = max(d[i-2][0] + stairs[i], d[i-2][1] + stairs[i]);
    }

    cout << max(d[n][0], d[n][1]);

}