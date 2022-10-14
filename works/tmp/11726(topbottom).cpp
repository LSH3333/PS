#include <iostream>
using namespace std;

int d[1010];

int dp(int n)
{
    if(n <= 2) return n;
    if(d[n] > 0) return d[n];

    d[n] = (dp(n-1) + dp(n-2)) % 10007;
    return d[n];
}

int main()
{

    int n; cin >> n;

    cout << dp(n);
}