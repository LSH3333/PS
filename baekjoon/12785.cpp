#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1000007

int R, C;
int tr, tc;
long long d[210][210];

int main()
{
    cin >> C >> R;
    cin >> tc >> tr;
    long long ans1, ans2;

    d[1][1] = 1;
    for(int r = 1; r <= tr; r++)
    {
        for(int c = 1; c <= tc; c++)
        {
            long long sum = 0;
            if(r-1 > 0) sum += d[r-1][c] % MOD;
            if(c-1 > 0) sum += d[r][c-1] % MOD;
            d[r][c] += sum % MOD;
        }
    }
    ans1 = d[tr][tc] % MOD;
    memset(d, 0, sizeof(d));

    d[tr][tc] = 1;
    for(int r = tr; r <= R; r++)
    {
        for(int c = tc; c <= C; c++)
        {
            long long sum = 0;
            if(r-1 > 0) sum += d[r-1][c] % MOD;
            if(c-1 > 0) sum += d[r][c-1] % MOD;
            d[r][c] += sum % MOD;
        }
    }
    ans2 = d[R][C] % MOD;

    cout << (ans1 * ans2) % MOD;
}