#include <iostream>
using namespace std;

#define MOD 1000000009
int d[100010];

int main()
{
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    d[3] = 2;
    for(int i = 4; i <= 100000; i++)
    {
        int a = 0, b = 0, c = 0;
        if(i-2 >= 0) a = d[i-2] % MOD;
        if(i-4 >= 0) b = d[i-4] % MOD;
        if(i-6 >= 0) c = d[i-6] % MOD;
        d[i] = (a + b) % MOD;
        d[i] = (d[i] + c) % MOD;
    }

    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        cout << d[N] << '\n';
    }

}