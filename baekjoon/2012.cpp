#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long arr[500002];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    sort(arr+1, arr+n+1);

    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += abs(arr[i]-i);
    }

    cout << ans;

}