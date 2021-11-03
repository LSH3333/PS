#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

int longest = 0;
vector<int> ans;

void IsItLongest()
{
    // 현재 벡터의 크기가 longest보다 크다면 갱신
    if(v.size() > longest)
    {
        ans.clear();

        for(int x : v)
            ans.push_back(x);

        longest = ans.size();
    }

    v.clear();
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        // 첫번째 수
        int num = n;
        v.push_back(num);
        // 두번째 수
        num = i;
        v.push_back(i);

        int idx = 2;
        while(num >= 0)
        {
            num = v[idx-2] - v[idx-1];
            v.push_back(num);
            idx++;
        }

        v.pop_back(); // 마지막 음수 제거

        IsItLongest();
    }


    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << x << ' ';

}