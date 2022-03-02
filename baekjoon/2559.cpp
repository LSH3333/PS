#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num; v.push_back(num);
    }

    int sum = 0;
    for(int i = 0; i < k; i++) sum += v[i];

    int left = 0, right = k, ans = sum;
    while(right < n)
    {
        sum += v[right++];
        sum -= v[left++];
        ans = max(ans, sum);
    }
    cout << ans;
}