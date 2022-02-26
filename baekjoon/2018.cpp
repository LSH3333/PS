#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;

    int left = 1, right = 1, sum = 0, cnt = 0;
    while(right <= n+1)
    {
        if(sum > n)
        {
            sum -= left;
            left++;
        }
        else if(sum < n)
        {
            sum += right;
            right++;
        }
        else if(sum == n)
        {
            cnt++;
            sum += right;
            right++;
        }
    }

    cout << cnt;
}