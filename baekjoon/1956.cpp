#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000000
int V, E;
vector<pair<int,int>> edges[410];
int dis[410][410];

void dijkstra(int _node)
{
    vector<int> d(V+1, INF);
    d[_node] = 0;
    // distance, node
    queue<pair<int,int>> q;
    q.push({0, _node});

    while(!q.empty())
    {
        int node = q.front().second;
        int distance = q.front().first * -1;
        q.pop();

        if(d[node] < distance) continue;

        for (auto next: edges[node])
        {
            int nextNode = next.first;
            int nextDistance = distance + next.second;
            if(d[nextNode] > nextDistance)
            {
                d[nextNode] = nextDistance;
                q.push({-nextDistance, nextNode});
            }
        }
    }

    for(int i = 1; i <= V; i++)
    {
        dis[_node][i] = d[i];
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> V >> E;

    vector<int> minE(V+1, INF);
    int a, b, c;
    for(int i = 1; i <= E; i++)
    {
        cin >> a >> b >> c;
        edges[a].push_back({b,c});

    }

    for(int node = 1; node <= V; node++)
    {
        dijkstra(node);
    }

//    for(int i = 1; i <= V; i++)
//    {
//        for(int j = 1; j <= V; j++)
//        {
//            cout << dis[i][j] << ' ';
//        } cout << endl;
//    }

    int ans = INF;
    for(int i = 1; i <= V; i++)
    {
        for(int j = 1; j <= V; j++)
        {
            if(i == j) continue;
            ans = min(dis[i][j] + dis[j][i], ans);
        }
    }
    if(ans == INF) cout << -1;
    else cout << ans;
}