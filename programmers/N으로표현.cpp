#include <string>
#include <vector>
#include <iostream>
using namespace std;

int n, Number;
int answer = 10;

void dfs(int num, int depth)
{
    if(depth > 8) return;

    if(num == Number)
    {
        answer = min(answer, depth);
        return;
    }

    int nextNum = 0;
    for(int i = 1; i <= 8; i++)
    {
        nextNum = nextNum * 10 + n;
        dfs(num + nextNum, depth+i);
        dfs(num - nextNum, depth+i);
        dfs(num * nextNum, depth+i);
        dfs(num / nextNum, depth+i);
    }
}

int solution(int N, int number)
{
    n = N; Number = number;
    dfs(0, 0);
    if(answer > 8) return -1;
    return answer;
}
