#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;

    int left = 0;
    int right = *max_element(arr, arr+n);
    int ans = (left + right) / 2;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] <= mid) sum += arr[i];
            else sum += mid;
        }

        if(sum <= m)
        {
            left = mid + 1;
            ans = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans;
}