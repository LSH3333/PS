#include <iostream>
using namespace std;

long long d[1010][1010];
#define MOD 1000000009

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    d[1][1] = 1;
    d[2][1] = 1; d[2][2] = 1;
    d[3][1] = 1; d[3][2] = 2; d[3][3] = 1;

    for(int i = 4; i <= 1000; i++)
    {
        for(int j = 2; j <= 1000; j++)
        {
            d[i][j] += (d[i-1][j-1] % MOD) + (d[i-2][j-1] % MOD) + (d[i-3][j-1] % MOD);
        }
    }

    int T; cin >> T;
    while(T--)
    {
        int N, M; cin >> N >> M;
        cout << d[N][M] % MOD << '\n';
    }

}