#include <iostream>
using namespace std;

#define MOD 1000000009
long long d[33334];

int main()
{
    int N; cin >> N;
    d[1] = 0;
    d[2] = 2;
    for(int i = 3; i <= N; i++)
    {
        d[i] = (d[i-1] * 3) % MOD;
    }
    cout << d[N];
}