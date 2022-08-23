#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int d[101][10001];
int T, K;
int coin[101]; // 동전의 종류
int coinNum[101]; // 동전의 갯수

int dp(int amount, int idx)
{
    if(amount == T) // 조건 만족
    {
        return 1;
    }
    if(idx == K || amount > T) // 조건 벗어남
    {
        return 0;
    }
    if(d[idx][amount] != -1)
    {
        return d[idx][amount];
    }

    int res = 0;
    for(int i = 0; i <= coinNum[idx]; i++)
    {
        int cost = coin[idx] * i;
        res += dp(amount + cost, idx + 1);
    }

    return d[idx][amount] = res;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> T >> K;
    for(int i = 0; i < K; i++)
    {
        int n, p; cin >> n >> p;
        coin[i] = n;
        coinNum[i] = p;
    }
    memset(d, -1, sizeof(d));
    cout << dp(0, 0);

}