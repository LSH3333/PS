#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int _number;
int answer = 9;

void dfs(int num, int depth)
{
    if(depth > 8) return;
    if(num == _number)
    {
        answer = min(answer, depth);
        return;
    }

    int tmp = n;
    for(int i = 1; i <= 7; i++)
    {
        dfs(num + tmp, depth + i);
        dfs(num - tmp, depth + i);
        dfs(num * tmp, depth + i);
        dfs(num / tmp, depth + i);

        tmp = tmp * 10 + n;
    }
}

int solution(int N, int number)
{
    n = N;
    _number = number;
    dfs(0, 0);
    if(answer > 8) return -1;
    return answer;
}
