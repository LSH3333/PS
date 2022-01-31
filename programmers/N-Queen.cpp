#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N;
int answer = 0;

bool Check(int r, int c, vector<vector<bool>> &mark)
{
    int cnt = 0;
    if(r == 0) return true;
    while(r > 0)
    {
        r--; cnt++;
        if(mark[r][c]) return false;
        if(c-cnt >= 0 && mark[r][c-cnt]) return false;
        if(c+cnt < N && mark[r][c+cnt]) return false;
    }
    return true;
}

void dfs(int r, vector<vector<bool>> &mark)
{
    if(r == N)
    {
        answer++;
        return;
    }

    for(int i = 0; i < N; i++)
    {
        if(mark[r][i]) continue;
        if(!Check(r, i, mark)) continue;
        mark[r][i] = true;
        dfs(r+1, mark);
        mark[r][i] = false;
    }
}

int solution(int n)
{
    N = n;
    answer = 0;
    vector<vector<bool>> mark(15, vector<bool>(15, false));

    dfs(0, mark);

    return answer;
}

int main()
{
    cout << solution(4);
}