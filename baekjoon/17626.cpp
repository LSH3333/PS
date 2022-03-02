#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// dp[i]는 i의 최소 제곱수
int dp[50001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 3;
    for(int i = 4; i <= n; i++)
    {
        int minVal = 10;

        bool trigger = false;
        for(int j = 1; j * j <= i; j++)
        {
            if(j * j == i) { dp[i] = 1; trigger = true; break; }
            if(dp[i-j*j] == 4) continue;
            minVal = min(minVal, dp[i-j*j]);
        }
        if(!trigger) dp[i] = minVal+1;
    }

    cout << dp[n];
}