#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int d[1010];
    d[1] = 1;
    d[2] = 2;

    for(int i = 1; i <= 1000; i++)
    {
        int sum = 0;
        for(int j = 1; j <= i/2; j++)
        {
            sum += d[j];
        }
        d[i] = sum + 1;
    }

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << d[n] << '\n';
    }

}