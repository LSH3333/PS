#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, x; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cin >> x;

    sort(v.begin(), v.end());

    int left = 0, right = n-1, sum = 0, cnt = 0;
    while(left < right)
    {
        sum = v[left] + v[right];
        if(sum == x) { cnt++; right--; }
        else if(sum < x) left++;
        else right--;
    }

    cout << cnt;
}