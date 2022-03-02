#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, s; cin >> n >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        // 길이 1이 답이라면 바로 리턴함
        if(v[i] >= s) { cout << 1; return 0; }
    }

    int left = 0, right = 0, len = 1;
    int sum = v[0];
    int ans = 200000;
    while(left <= right && right < n)
    {
        if(sum >= s)
        {
            ans = min(ans, len);
            sum -= v[left++]; len--;
        }
        else if(sum < s)
        {
            sum += v[++right];
            len++;
        }
    }

    if(ans == 200000) cout << 0;
    else cout << ans;
}