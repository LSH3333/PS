#include <iostream>
using namespace std;

int n;
long long ans = 0;
int road[100001];
int cost[100001];

int main()
{
    cin >> n;
    for(int i = 0; i < n-1; i++)
        cin >> road[i];
    for(int i = 0; i < n; i++)
        cin >> cost[i];

    long long minCost = 2000000001;
    for(int i = 0; i < n-1; i++)
    {
        // 현재까지 가격중 가장 낮은 가격으로 계속 주유한다
        if(cost[i] < minCost)
        {
            minCost = cost[i];
        }

        // 가장 낮은 가격 * 다음 도시까지 거리
        ans += minCost * road[i];

    }
    cout << ans;
}