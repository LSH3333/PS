#include <iostream>
using namespace std;

long long d[80];

int main()
{
    d[0] = 1; d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i = 4; i <= 68; i++)
    {
        d[i] = d[i-1] + d[i-2] + d[i-3] + d[i-4];
    }

    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        cout << d[N] << '\n';
    }

}