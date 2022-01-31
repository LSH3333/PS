#include <iostream>
#include <vector>
using namespace std;

int N, ans;
int arr[14];

bool Check(int r, int c)
{
    for(int i = 1; i < r; i++)
    {
        // 같은 열에 퀸 존재하는지 확인
        if(arr[i] == c) return false;
        // 대각선에 퀸 존재하는지 확인
        if(abs(r-i) == abs(c-arr[i])) return false;
    }
    return true;
}

void dfs(int row)
{
    if(row == N+1)
    {
        ans++;
        return;
    }

    for(int i = 1; i <= N; i++)
    {
        if(!Check(row, i)) continue;
        arr[row] = i;
        dfs(row+1);
        arr[row] = 0;
    }
}

int solution(int n)
{
    N = n;
    dfs(1);
    return ans;
}