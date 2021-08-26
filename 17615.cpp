#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
string ball;

int main()
{
    cin >> n;
    cin >> ball;

    // R,B의 총 갯수
    int rCnt = 0, bCnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(ball[i] == 'R') rCnt++;
        else bCnt++;
    }

    // 왼쪽, 오른쪽에 연속으로 붙어있는 같은색 볼의 갯수
    char left = ball[0];
    int leftCnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(ball[i] == left)
            leftCnt++;
        else
            break;
    }

    char right = ball[n-1];
    int rightCnt = 1;
    for(int i = n-2; i >= 0; i--)
    {
        if(ball[i] == right)
            rightCnt++;
        else
            break;
    }

    // 왼쪽, 오른쪽에 연속으로 붙어있는 볼들의 수
    int leftR, leftB, rightR, rightB;
    if(left == 'R')
    {
        leftR = leftCnt;
        leftB = 0;
    }
    else
    {
        leftB = leftCnt;
        leftR = 0;
    }
    if(right == 'R')
    {
        rightR = rightCnt;
        rightB = 0;
    }
    else
    {
        rightB = rightCnt;
        rightR = 0;
    }


    // left:R, move:R
    int RR = rCnt - leftR;
    // left:B, move:B
    int BB = bCnt - leftB;
    // left:B, move:R
    int BR = rCnt - rightR;
    // left:R, move:B
    int RB = bCnt - rightB;

    // 최솟값 탐색
    int ans = min({RR,BB,BR,RB});

    cout << ans;



}