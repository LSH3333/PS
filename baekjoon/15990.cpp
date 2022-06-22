#include <iostream>
using namespace std;
#define MOD 1000000009
long long d[100010][3];

int main()
{
    d[1][0] = 1; d[1][1] = 0; d[1][2] = 0;
    d[2][0] = 0; d[2][1] = 1; d[2][2] = 0;
    d[3][0] = 1; d[3][1] = 1; d[3][2] = 1;

    for(int i = 4; i <= 100000; i++)
    {
        d[i][0] = (d[i-1][1] + d[i-1][2]) % MOD;
        d[i][1] = (d[i-2][0] + d[i-2][2]) % MOD;
        d[i][2] = (d[i-3][0] + d[i-3][1]) % MOD;
    }

    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        cout << (d[N][0] + d[N][1] + d[N][2]) % MOD << '\n';
    }

}