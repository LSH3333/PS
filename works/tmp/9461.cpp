#include <iostream>
using namespace std;

int main()
{
    long long d[102];
    d[0] = 0;
    d[1] = 1;
    d[2] = 1;
    d[3] = 1;

    for(int i = 4; i < 101; i++)
        d[i] = d[i-2] + d[i-3];

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << d[n] << '\n';
    }
}