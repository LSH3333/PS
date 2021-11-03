#include <iostream>
using namespace std;

int d[50];

int dp(int n)
{
    if(n <= 1) return n;
    if(d[n] > 0) return d[n];

    d[n] = dp(n-1) + dp(n-2);
    return d[n];
}

int main()
{
    int n;
    cin >> n;

    cout << dp(n);
}