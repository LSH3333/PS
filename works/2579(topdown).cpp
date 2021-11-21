#include <iostream>
#include <algorithm>
using namespace std;

int d[301], a[301];

int dp(int n)
{
    // base check
    if(n == 0) return a[0];
    else if(n == 1) return a[0] + a[1];
    else if(n == 2) return max(a[0] + a[2], a[1] + a[2]);

    // memoization
    if(d[n] > 0) return d[n];

    // recurrence relation
    d[n] = dp(n - 2) + a[n];
    int v = dp(n - 3) + a[n-1] + a[n];
    if(d[n] < v) d[n] = v;

    return d[n];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << dp(n-1);
}