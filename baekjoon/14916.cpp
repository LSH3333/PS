#include <iostream>
using namespace std;

#define INF 10000000
int d[100010];

int main()
{
    int N; cin >> N;
    for(int i = 0; i <= N; i++) d[i] = INF;
    d[2] = 1;
    d[4] = 2;
    d[5] = 1;
    for(int i = 6; i <= N; i++)
    {
        d[i] = min(d[i-2], d[i-5]) + 1;
    }

    if(d[N] == INF) cout << -1;
    else
        cout << d[N];
}