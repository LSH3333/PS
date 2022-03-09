#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
vector<int> ans;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        v.push_back(num);
    }

    ans.push_back(-1);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int num = v[i];
        if(num > ans.back())
        {
            ans.push_back(num); cnt++;
        }
        else
        {
            int idx = lower_bound(ans.begin(), ans.end(), num) - ans.begin();
            ans[idx] = num;
        }
    }

    cout << ans.size()-1;
}