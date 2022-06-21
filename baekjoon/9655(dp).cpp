#include <iostream>
using namespace std;

// dp[N] = M : 돌이 N개 일때 최소 M번의 게임 진행함
int dp[1001];

int main()
{
    int stone; cin >> stone;
    dp[1] = 1; // 상근
    dp[2] = 2; // 창영
    dp[3] = 1; // 상근

    for(int i = 4; i <= stone; i++)
    {
        dp[i] = min(dp[i-1]+1, dp[i-3]+1);
    }

    if(dp[stone] % 2 == 0) cout << "CY";
    else cout << "SK";
}