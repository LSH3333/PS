#include <iostream>
using namespace std;

#define MOD 1000000
int N;
// L ??, ??? ?? A ??, ??
int d[2][3][1001];

int main() {
    cin >> N;
    d[0][0][1] = 1;
    d[1][0][1] = 1;
    d[0][1][1] = 1;

    for(int i = 2; i <= N; i++) {
        d[0][0][i] = (d[0][0][i-1] + d[0][1][i-1] + d[0][2][i-1]) % MOD;
        d[1][0][i] = (d[0][0][i-1] + d[1][0][i-1] + d[0][1][i-1] + d[0][2][i-1] + d[1][1][i-1] + d[1][2][i-1]) % MOD;
        d[0][1][i] = (d[0][0][i-1]) % MOD;
        d[1][1][i] = (d[1][0][i-1]) % MOD;
        d[0][2][i] = (d[0][1][i-1]) % MOD;
        d[1][2][i] = (d[1][1][i-1]) % MOD;
    }

    int answer = 0;
    for(int l = 0; l < 2; l++) {
        for(int a = 0; a < 3; a++) {
            answer = (answer + d[l][a][N]) % MOD;
        }
    }

    cout << answer % MOD;
}