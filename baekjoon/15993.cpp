#include <iostream>
using namespace std;

#define MAX 100000
#define MOD 1000000009

// odd, even
int dp[MAX+1][2];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    dp[0][1] = 1;

    for(int i = 1; i <= MAX; i++) {
        if(i-1 >= 0) {
            dp[i][0] = (dp[i][0] + dp[i-1][1]) % MOD;
            dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
        }
        if(i-2 >= 0) {
            dp[i][0] = (dp[i][0] + dp[i-2][1]) % MOD;
            dp[i][1] = (dp[i][1] + dp[i-2][0]) % MOD;
        }
        if(i-3 >= 0) {
            dp[i][0] = (dp[i][0] + dp[i-3][1]) % MOD;
            dp[i][1] = (dp[i][1] + dp[i-3][0]) % MOD;
        }
    }

    int N; cin >> N;
    while(N--) {
        int n; cin >> n;
        cout << dp[n][0] << ' ' << dp[n][1] << '\n';
    }
}