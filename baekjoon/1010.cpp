#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        long long n, m; cin >> n >> m;
        long long d[33][33] = {0, };

        for(long long i = 1; i <= m; i++) d[1][i] = i;

        for(long long i = 2; i <= n; i++)
        {
            for(long long j = i; j <= m; j++)
            {
                for(long long a = 1; a <= j-1; a++) d[i][j] += d[i-1][a];
            }
        }


        cout << d[n][m] << '\n';
    }



}