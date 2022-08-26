#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> edges[2010];

void dfs(int node, int depth, vector<bool> &visited, bool &trigger)
{
    if(depth == 4)
    {
        trigger = true;
        return;
    }

    for(auto next : edges[node])
    {
        if(visited[next]) continue;
        visited[next] = true;
        dfs(next, depth+1, visited, trigger);
        visited[next] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(int node = 0; node < N; node++)
    {
        vector<bool> visited(N+1, false);
        bool trigger = false;
        visited[node] = true;
        dfs(node, 0, visited, trigger);

        if(trigger) { cout << 1; return 0; }
    }
    cout << 0;
}