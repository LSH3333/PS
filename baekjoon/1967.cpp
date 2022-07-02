#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> edges[10001];
int answer;

void dfs(int node, int total, vector<bool> &mark)
{
    answer = max(answer, total);

    for(auto x : edges[node])
    {
        int nextNode = x.first;
        int val = x.second;
        if(mark[nextNode]) continue;
        mark[nextNode] = true;
        dfs(nextNode, total+val, mark);
        mark[nextNode] = false;
    }
}

int main()
{
    int N; cin >> N;
    int last;
    for(int i = 0; i < N-1; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
        last = a;
    }


    // leaf nodes
    for(int i = last+1; i <= N; i++)
    {
        vector<bool> mark(N+1, false);
        mark[i] = true;
        dfs(i, 0, mark);
    }
    cout << answer;
}