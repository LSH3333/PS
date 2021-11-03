#include <iostream>
#include <algorithm>
using namespace std;

long long n;
long long dice[6];

// 최소가 되는 인접한 두면의합 찾음
long long FindMinTwoSide()
{
    long long minSum = 99999;
    int idx[6] = {5,4,3,2,1,0};
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            // 같은면, 반대면 계산 안함
            // 반대면은 인접하지 못하므로
            if(j == i || j == idx[i]) continue;
            long long sum = dice[i] + dice[j];

            minSum = min(sum ,minSum);
        }
    }
    return minSum;
}

// 최소가 되는 인접한 세면의합 찾음
long long FindMinThreeSide()
{
    int idx[4] = {0,1,5,4};
    int idx2[4] = {1,5,4,0};

    long long sum = dice[0] + dice[1] + dice[2];

    for(int i = 0; i < 4; i++)
    {
        if(dice[idx[i]] + dice[idx2[i]] + dice[3] > dice[idx[i]] + dice[idx2[i]] + dice[2])
            sum = min(sum, dice[idx[i]] + dice[idx2[i]] + dice[2]);
        else
            sum = min(sum, dice[idx[i]] + dice[idx2[i]] + dice[3]);
    }
    return sum;
}

// 마주 보는 세쌍의 면중 작은값을 더한값 ]
long long FindMinThreeSide2()
{
    int a1 = min(dice[0], dice[5]);
    int a2 = min(dice[1], dice[4]);
    int a3 = min(dice[2], dice[3]);
    return a1+a2+a3;
}

int main()
{
    cin >> n;
    long long min_num = 55;
    for(int i = 0; i < 6; i++)
    {
        cin >> dice[i];
        min_num = min(min_num, dice[i]);
    }

    // n=1일 경우 예외
    if(n == 1)
    {
        sort(dice, dice+6);
        int sum = 0;
        for(int i = 0; i < 5; i++)
        {
            sum += dice[i];
        }
        cout << sum;
        return 0;
    }

    // 한 면이 보이는 주사위
    long long oneSideNum = (n-2)*(n-2)+(n-2)*(n-1)*4;
    long long oneSide = oneSideNum * min_num;

    // 두 면이 보이는 주사위
    long long twoSideNum = (n-1) * 4 + (n-2) * 4;
    long long twoSide = twoSideNum * FindMinTwoSide();

    // 세 면이 보이는 주사위
    long long threeSideNum = 4;
    long long threeSide = threeSideNum * FindMinThreeSide2();

    long long ans = oneSide + twoSide + threeSide;

    cout << ans;

}