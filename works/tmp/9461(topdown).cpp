#include <iostream>
#include <algorithm>
using namespace std;

long long d[102];

long long dp(int n)
{
    if(n == 0) return 0;
    else if(n <= 3) return 1;

    if(d[n] > 0) return d[n];

    d[n] = dp(n-2) + dp(n-3);
    return d[n];
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << dp(n) << '\n';
    }

}