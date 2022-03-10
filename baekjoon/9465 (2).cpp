#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int a[3][100010] {0, };
        int d[3][100010] = {0, };

        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        d[0][0] = a[0][0];
        d[1][0] = a[1][0];
        d[2][0] = 0;

        for(int i = 1; i < n; i++)
        {
            d[0][i] = max(d[1][i-1]+a[0][i], d[2][i-1]+a[0][i]);
            d[1][i] = max(d[0][i-1]+a[1][i], d[2][i-1]+a[1][i]);
            d[2][i] = max(d[0][i-1], max(d[1][i-1], d[2][i-1]));
        }

        cout << max(d[0][n-1], max(d[1][n-1], d[2][n-1])) << '\n';
    }

}