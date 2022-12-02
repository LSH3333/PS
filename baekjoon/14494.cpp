#include <iostream>
using namespace std;

#define MOD 1000000007
long long d[1010][1010];

int main() {
    int N, M; cin >> N >> M;
    d[1][1] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(i == 1 && j == 1) continue;
            d[i][j] = (d[i-1][j] + d[i][j-1] + d[i-1][j-1]) % MOD;
        }
    }

    cout << d[N][M] % MOD;
}
