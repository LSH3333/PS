#include <iostream>
#include <vector>
using namespace std;

int n;
int ans = 0;
vector<pair<int,int>> egg;

// 깨진 계란수를 샌다
int CountBrokenEggs()
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(egg[i].first <= 0)
            cnt++;
    }
    return cnt;
}

void dfs(int onHand)
{
    // 손에 든게 마지막 계란이라면
    if(onHand == n)
    {
        ans = max(ans, CountBrokenEggs());
        return;
    }

    // 손에 든 계란이 깨져있다면 다음 계란을 들러간다
    if(egg[onHand].first <= 0)
        dfs(onHand+1);

    // 손에 든 계란이 안깨진 상태이다
    else
    {
        // 계란을 부딪혔는지 아닌지 판단
        // 더이상 칠수 있는 계란이 없다면 false로 남을 것이다
        bool hitEgg = false;
        for(int i = 0; i < n; i++)
        {
            // 손에 든 계란이거나 이미 깨진계란 이라면 부딪힐수없다
            if(i == onHand || egg[i].first <= 0) continue;

            // 손에 든 계란과 다른 계란을 부딪친다
            egg[onHand].first = egg[onHand].first - egg[i].second;
            egg[i].first = egg[i].first - egg[onHand].second;

            // 다음 계란을 집는다
            dfs(onHand+1);

            // 다른 계란을 쳐보기 위해 계란을 치기전으로 복원한다
            egg[onHand].first = egg[onHand].first + egg[i].second;
            egg[i].first = egg[i].first + egg[onHand].second;

            hitEgg = true; // 어떤 계란이던지 부딪쳤다
        }
        // 어떤 계란도 부딪히지 못했다면 마지막 남은 계란
        if(!hitEgg) dfs(n);
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int s, w;
        cin >> s >> w;
        egg.push_back({s,w});
    }

    dfs(0);

    cout << ans;

}
