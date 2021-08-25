#include <iostream>
#include <algorithm>
using namespace std;

int n, doughPrize, toppingPrize, doughCal;
int toppingCal[10010];

int main()
{
    cin >> n >> doughPrize >> toppingPrize >> doughCal;
    for(int i = 0; i < n; i++)
        cin >> toppingCal[i];

    sort(toppingCal, toppingCal+n, greater<>());

    int cal = doughCal;
    int prize = doughPrize;
    // 토핑을 전혀 선택하지 않는 경우
    int ans = doughCal / doughPrize;
    for(int i = 0; i < n; i++)
    {
        cal += toppingCal[i];
        prize += toppingPrize;

        ans = max(ans, cal/prize);
    }

    cout << ans;
}