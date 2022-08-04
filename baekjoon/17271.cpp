#include <iostream>
using namespace std;

int N, M;
int d[10001];
#define MOD 1000000007

int main()
{
    cin >> N >> M;
    d[1] = 1;
    d[M] = 2;
    for(int i = 2; i <= N; i++)
    {
        if(i == M) continue;
        int a = d[i-1] % MOD;
        int b = 0;
        if(i-M >= 0) b = d[i-M] % MOD;
        d[i] = (a + b) % MOD;
    }

//    for(int i = 1; i <= N; i++) cout << d[i] << ' ';
    cout << d[N] % MOD;
}