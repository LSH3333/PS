#include <iostream>
using namespace std;

int n;
long long w;
long long coin[51];

int main()
{
    cin >> n >> w;
    for(int i = 0; i < n; i++)
        cin >> coin[i];

    if(n == 1)
    {
        cout << w;
        return 0;
    }

    long long myCoin = 0;
    // 첫날이 저점이면
    if(coin[1] - coin[0] > 0)
    {
        // 살 코인 갯수
        long long buy = w / coin[0];
        w -= coin[0] * buy;
        myCoin += buy;
    }

    for(int i = 1; i < n-1; i++)
    {
        // 이전값이 작거나 같고, 다음값이 작다 : 고점 : 팔아야함
        if(coin[i-1] <= coin[i] && coin[i+1] < coin[i])
        {
            // 자산 증가
            w += coin[i] * myCoin;
            // 코인 다 팜
            myCoin = 0;
        }
            // 이전값이 크거나 같고, 다음값이 크다 : 저점 : 사야함
        else if(coin[i-1] >= coin[i] && coin[i+1] > coin[i])
        {
            // 자산 감소
            long long buy = w / coin[i];
            w -= coin[i] * buy;
            // 코인 증가
            myCoin += buy;
        }
    }

    // 마지막날 남은 코인 있다면 다팜
    if(myCoin > 0)
    {
        w += coin[n-1] * myCoin;
    }

    cout << w;
}
