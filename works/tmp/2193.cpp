#include <iostream>
using namespace std;


int main()
{
    long long d[100][2];
    int n;
    cin >> n;

    d[1][0] = 0; // n 자리에서 0으로 끝나는
    d[1][1] = 1; // n 자리에서 1로 끝나는

    for(int i = 2; i <= n; i++)
    {
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }

    cout << d[n][0] + d[n][1];
}