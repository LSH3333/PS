#include <iostream>
using namespace std;

int main()
{
    int d[11];
    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    for(int i = 4; i < 11; i++)
    {
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << d[n] << '\n';
    }
}