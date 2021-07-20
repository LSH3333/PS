#include <iostream>
#include <cmath>
using namespace std;

int n;
int ans = 0;
int col[16];

void Init()
{
    for(int i = 0; i <= n; i++)
        col[i] = 0;
}

// level에 둔 퀸과 이전에 level에 둔 퀸들이 충돌하는지 판별
bool IsPromising(int level)
{
    for(int i = 1; i < level; i++)
    {
        // 같은 열에 있다면 충돌함
        if(col[i] == col[level])
            return false;
            // 현재 level의 퀸과 i레벨의 퀸이 대각선에 있다면 충돌
        else if(level-i == abs(col[level] - col[i]))
            return false;
    }
    // 같은 열에 있지도 않고 & 대각선에도 없으면 promising 하다
    return true;
}

void NQueen(int row)
{
    // n행까지 모든 퀸을 성공적으로 놓았다
    if(row == n)
    {
        ans++;
    }

    for(int i = 1; i <= n; i++)
    {
        // 다음 행에 1열부터 n열까지 퀸을 놓아본다
        col[row+1] = i;
        // 다음 행에 놓아본 퀸이 promising 하다면 진행한다
        if(IsPromising(row+1))
            NQueen(row+1);
        else // promising 하지 않다면 놓아본 퀸을 거둔다
            col[row+1] = 0;
    }
    // 여기 까지 왔다는 것은 1열부터 N열까지 퀸을 놓을곳이 없다 , 결정 번복
    col[row] = 0;

}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        // 1행의 1열부터 n열까지 순서대로 놔본다
        col[1] = i;
        NQueen(1);
        Init();
    }

    cout << ans;
}
