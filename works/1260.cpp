#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001
using namespace std;

int N, M, V;
vector<vector<int>> edge(MAX, vector<int>(0,0));
bool mark[1001];

void dfs(int n)
{
    if(mark[n]) return;

    cout << n << ' ';
    mark[n] = true;
    for(auto x : edge[n]) dfs(x);
}

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    mark[n] = true;

    while(!q.empty())
    {
        int v = q.front();
        cout << v << ' ';
        q.pop();

        for(auto x : edge[v])
        {
            if(mark[x]) continue;
            q.push(x);
            mark[x] = true;
        }
    }

}


int main()
{
    cin >> N >> M >> V;
    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for(int i = 1; i <= N; i++)
        sort(edge[i].begin(), edge[i].end());

    dfs(V);
    cout << '\n';
    fill_n(mark, sizeof(mark), false);
    bfs(V);
}