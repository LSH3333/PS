#include <iostream>
using namespace std;
#define MOD 1000000000
long long d[101][11];

int main() {
    int n;
    cin >> n;

    d[1][0] = 0;
    for(int i = 1; i < 10; i++) d[1][i] = 1;

    for(int i = 2; i <= n; i++) {
        for(int a = 0; a <= 9; a++) {
            if(a == 0) d[i][0] = d[i-1][1] % MOD;
            else if(a == 9) d[i][9] = d[i-1][8] % MOD;
            else {
                d[i][a] = (d[i-1][a-1] + d[i-1][a+1]) % MOD;
            }
        }
    }


    long long ans = 0;
    for(int i = 0; i < 10; i++) ans += d[n][i];
    cout << ans % MOD;


}