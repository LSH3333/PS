#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<bool> mark(201);

void dfs(int n, vector<vector<int>> &edges)
{
    if(mark[n]) return;

    mark[n] = true;
    for(auto x : edges[n]) dfs(x, edges);
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<int>> edges(n+1, vector<int>(0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j || computers[i][j] != 1) continue;
            edges[i].push_back(j);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(mark[i]) continue;
        dfs(i, edges);
        answer++;
    }

    return answer;
}
