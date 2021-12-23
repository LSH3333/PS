#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> edge(20001, vector<int>(0,0));
vector<int> mark(20001, -1);
int maximum = 0;

void bfs()
{
    mark[1] = 0;
    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int v = q.front();
        int vl = mark[v];
        if(vl > maximum) maximum = vl;
        for(int i = 0; i < edge[v].size(); i++)
        {
            int nv = edge[v][i];
            if(mark[nv] != -1) continue;
            q.push(nv);
            mark[nv] = vl + 1;
        }
        q.pop();
    }
}

int solution(int n, vector<vector<int>> vertex) {
    int answer = 0;

    for(int i = 0; i < vertex.size(); i++)
    {
        int a = vertex[i][0];
        int b = vertex[i][1];
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    bfs();

    for(int i = 2; i <= n; i++)
    {
        if(mark[i] == maximum) answer++;
    }

    return answer;
}
