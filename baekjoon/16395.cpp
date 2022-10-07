#include <iostream>
using namespace std;

int d[40][40];

int main()
{
    int n, k;
    cin >> n >> k;

    d[1][1] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            d[i][j] = d[i-1][j-1] + d[i-1][j];
        }
    }

    cout << d[n][k];
}