#include <iostream>
using namespace std;

int n;
int ans = 0;
// 인덱스가 행, 값이 열
// col[0] = 0 은 (0,0)에 퀸 놓음
// col[1] = 2 는 (1,2)에 퀸 놓음
int col[16] = {-1,};

// (r,c)에 퀸을 놓을수 있는지 판단
bool Check(int r, int c)
{
    // r행,c열에 퀸을 놓아봄
    col[r] = c;
    for(int i = 0; i < r; i++)
    {
        // 같은 열에 있다면 충돌함
        if(col[i] == col[r])
            return false;
        // 현재 row의 퀸과 i레벨의 퀸이 대각선에 있다면 충돌함
        else if(r-i == abs(col[r]-col[i]))
            return false;
    }
    return true;
}

void NQueen(int row)
{
    if(row == n)
    {
        ans++;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        // (row,i)에 놓을수 있다면 놓는다
        if(Check(row, i))
        {
            col[row] = i;
            NQueen(row+1);
            col[row] = -1;
        }
    }
}

int main()
{
    cin >> n;

    NQueen(0);

    cout << ans;
}