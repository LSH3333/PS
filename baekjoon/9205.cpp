#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int GetDist(const pair<int,int> &p1, const pair<int,int> &p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

bool bfs(int N, const vector<pair<int,int>> &nodes)
{
    vector<bool> visited(N+2, false);
    queue<pair<int,int>> q;
    visited[0] = true;
    q.push(nodes.front());

    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();

        if(GetDist(cur, nodes.back()) <= 1000) return true;

        for(int i = 1; i < N+1; i++)
        {
            if(visited[i]) continue;
            if(GetDist(cur, nodes[i]) <= 1000)
            {
                visited[i] = true;
                q.push(nodes[i]);
            }
        }
    }
    return false;
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        vector<pair<int,int>> nodes(N+2);
        cin >> nodes[0].first >> nodes[0].second;
        for(int i = 1; i < N+1; i++)
        {
            cin >> nodes[i].first >> nodes[i].second;
        }
        cin >> nodes[N+1].first >> nodes[N+1].second;

        bool ret = bfs(N, nodes);
        if(ret) cout << "happy\n";
        else cout << "sad\n";
    }


}