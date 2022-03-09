#include <iostream>
#include <algorithm>
using namespace std;

long long n, k;

long long Count(long long mid)
{
    // mid 보다 작거나 같은 숫자 갯수
    long long cnt = 0;
    for(long long i = 1; i <= n; i++)
    {
        if(i * n <= mid)
            cnt += n;
        else
            cnt += mid / i;
    }
    return cnt;
}

int main()
{
    cin >> n >> k;
    long long left = 1, right = n*n;
    long long ans = (left + right) / 2;
    while(left <= right)
    {
        long long mid = (left + right) / 2;

        long long cnt = Count(mid);
        if(cnt < k)
        {
            left = mid + 1;
        }
        else
        {
            ans = mid;
            right = mid - 1;
        }
    }
    cout << ans;
}