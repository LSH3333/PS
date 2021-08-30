#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> neg, pos;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if(num < 0) // 절댓값
            neg.push_back(num * -1);
        else
            pos.push_back(num);
    }

    sort(neg.begin(), neg.end(), greater<>());
    sort(pos.begin(), pos.end(), greater<>());

    // out of bound 방지
    for(int i = 0; i < m; i++)
    {
        neg.push_back(0);
        pos.push_back(0);
    }

    int ans = 0;
    for(int i = 0; i < neg.size(); i+=m)
    {
        ans += neg[i] * 2;
    }
    for(int i = 0; i < pos.size(); i+=m)
    {
        ans += pos[i] * 2;
    }

    // 음수좌표, 양수좌표 최댓값중 가장 큰 값은 마지막에 자리에 놓음으로서 왕복하지 않음
    int bigger = max(neg[0], pos[0]);
    ans -= bigger;
    cout << ans;

}