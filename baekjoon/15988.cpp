#include <iostream>
using namespace std;

#define MOD 1000000009

long long d[1000001];

int main()
{
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i = 4; i <= 1000000; i++)
    {
        d[i] = (d[i-1] + d[i-2] + d[i-3]) % MOD;
    }

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        cout << d[N] % MOD << '\n';
    }

}