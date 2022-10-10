#include <iostream>
#include <cmath>
using namespace std;

int N, goalR, goalC;

// (_r,_c)를 시작으로 하는 한 변의 길이 length 정사각형에서 (r,c)가 몇 사분면에 있는지 리턴
int FindArea(int length, int _r, int _c)
{
    // 0 사분면
    if(goalR - _r <= (length / 2)-1 && goalC - _c <= (length / 2) -1)
    {
        return 0;
    }
    // 1 사분면
    if(goalR - _r <= (length / 2) - 1 && goalC - _c <= length - 1)
    {
        return 1;
    }
    // 2 사분면
    if(goalR - _r <= length - 1 && goalC - _c <= (length / 2) - 1)
    {
        return 2;
    }
    // 3 사분면
    else
    {
        return 3;
    }
}

int dfs(int n, int startNum, int startR, int startC)
{
    if(n == 0)
    {
        return startNum;
    }

    int length = (int)pow(2, n);
    int cnt = (length / 2) * (length / 2);
    int area = FindArea(length, startR, startC);

    if(area == 0)
    {
        return dfs(n-1, startNum + (cnt * area), startR, startC);
    }
    else if(area == 1)
    {
        return dfs(n-1, startNum + (cnt * area), startR, startC + (length / 2));
    }
    else if(area == 2)
    {
        return dfs(n-1, startNum + (cnt * area), startR + (length / 2), startC);
    }
    else
    {
        return dfs(n-1, startNum + (cnt * area), startR + (length / 2), startC + (length / 2));
    }
}

int main()
{
    cin >> N >> goalR >> goalC;

    cout << dfs(N, 0, 0, 0);
}