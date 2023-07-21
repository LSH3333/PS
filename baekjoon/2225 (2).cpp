#include <iostream>
using namespace std;

#define MOD 1000000000

int N, K;
int d[210][210];

int main() {
    cin >> N >> K;
    for(int i = 0; i <= N; i++) {
        d[1][i] = 1;
        d[i][0] = 1;
    }

    for(int i = 2; i <= K; i++) {
        for(int j = 0; j <= N; j++) {
            d[i][j] = (d[i][j-1] + d[i-1][j]) % MOD;
        }
    }

    cout << d[K][N] % MOD;
}