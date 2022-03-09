#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

bool Count(long long mid)
{
    // mid보다 작은 숫자 갯수
    long long cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i * n < mid)
            cnt += n;
        else if(i * n == mid)
            cnt += n-1;
        else
        {
            if(mid % i == 0) cnt += mid / i - 1;
            else cnt += mid / i;
        }
    }
//    cout << "cnt: " << cnt << endl;
    // mid 보다 작거나 같은 값이 k개 이하로 존재
    if(cnt < k) return true;
    return false;
}

int main()
{
    cin >> n >> k;
    long long left = 1, right = n * n;
    long long ans = 0;
    while(left <= right)
    {
        long long mid = (left + right) / 2;
//        cout << left << ' ' << mid << ' ' << right << endl;
        if(Count(mid))
        {
//            cout << "T" << endl;
            left = mid + 1;
            ans = mid;
        }
        else
        {
//            cout << "F" << endl;
            right = mid - 1;
        }
    }
    cout << ans;
}