#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int mark[1000001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int h; cin >> h;
        // h에 화살 존재 하지 않음
        if(mark[h] == 0)
        {
            mark[h-1]++;
            ans++;
        }
            // h에 화살 존재
        else
        {
            mark[h]--;
            mark[h-1]++;
        }
    }
    cout << ans;
}