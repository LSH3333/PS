#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int ans = 0, ansSub = 99999999;

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                int sum = v[i] + v[j] + v[k];
                if(sum <= m && m-sum < ansSub)
                {
                    ansSub = m-sum;
                    ans = sum;
                }
            }
        }
    }
    cout << ans;
}