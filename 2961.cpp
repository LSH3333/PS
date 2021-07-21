#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int res = 1000000001;
// 재료. {신맛, 쓴맛}
vector<pair<int,int>> v;
bool mark[11];
vector<pair<int,int>> ans;

// 만들어진 조합에 대하여 신맛과 쓴맛의 차이를 구해 리턴한다
int Calculate()
{
    int s = 1; // 신맛은 곱하기므로 1로 초기화
    int b = 0;
    // 만들어진 조합에 대하여 총 신맛과 쓴맛을 구한다
    for(auto x : ans)
    {
        s *= x.first;
        b += x.second;
    }

    // 신맛과 쓴맛의 차이
    return abs(s-b);
}

// 조합 k개를 뽑는다
void dfs(int idx, int depth, int k)
{
    // k개를 뽑는 조합 만들어짐 
    if(depth == k)
    {
        res = min(res, Calculate());

        return;
    }

    for(int i = idx; i < n; i++)
    {
        if(mark[i]) continue;
        mark[i] = true;
        ans.push_back(v[i]);

        dfs(i, depth+1, k);

        mark[i] = false;
        ans.pop_back();
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int s,b;
        cin >> s >> b;
        v.push_back({s,b});
    }

    for(int i = 0; i < n; i++)
    {
        dfs(0, 0, i+1);
    }

    cout << res;
}