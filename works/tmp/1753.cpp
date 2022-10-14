#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 2000000000
using namespace std;

int V, E;
int start;

void Dijkstra(vector<int> &d, vector<pair<int,int>> graph[])
{
    d[start] = 0;
    // distance, node
    // 인접 노드 중 가중치 가장 작은 노드부터 방문해야 한다 
    // priority_queue는 first 기준 정렬이므로 distance가 first로 와야함 
    priority_queue<pair<int,int>> pq;
    pq.push({0, start});

    while(!pq.empty())
    {
        int distance = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        // 해당 노드의 기록되어 있는 최소비용이 더 작다
        if(d[cur] < distance) continue;

        for(int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int nextDistance = distance + graph[cur][i].second;

            if(nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push({ -nextDistance, next});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> V >> E >> start;
    // idx 정점에서 pair.first 정점으로 가는데 pair.second 비용
    vector<pair<int,int>> graph[V+1];
    for(int i = 0; i < E; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    vector<int> d(V+1, INF);
    Dijkstra(d, graph);

    for(int i = 1; i <= V; i++)
    {
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }
}