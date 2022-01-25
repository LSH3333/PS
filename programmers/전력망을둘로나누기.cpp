#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> edges(110, vector<int>(0));
int cnt = 0;

void dfs(int n, vector<bool> &mark, int cut)
{
    // 관계를 자른 노드는 이동하지 않음
    if(n == cut) return;
    cnt++;
    for(auto x : edges[n])
    {
        if(mark[x]) continue;
        mark[x] = true;
        dfs(x, mark, cut);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 110;

    // 관계 형성
    for(auto x : wires)
    {
        edges[x[0]].push_back(x[1]);
        edges[x[1]].push_back(x[0]);
    }

    for(auto x : wires)
    {
        int num1, num2;
        vector<bool> mark(n+1, false);
        cnt = 1;
        mark[x[0]] = true;
        dfs(x[0], mark, x[1]);
        fill(mark.begin(), mark.end(), false);
        num1 = cnt;

        cnt = 1;
        mark[x[1]] = true;
        dfs(x[1], mark, x[0]);
        num2 = cnt;

        answer = min(answer, abs(num1-num2));
    }
    return answer;
}