#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000000
using namespace std;

// graph[1] = {2,3} : 도시1에서 도시2가는데 버스비용이 3
vector<pair<int,int>> graph[1010];
long long d[1010] = {INF, }; // start 지점에서 각 노드까지 최소비용

void Dijkstra(int start)
{
    d[start] = 0;
    // distance, node
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, start});

    while(!pq.empty())
    {
        long long distance = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if(d[curNode] < distance) continue;

        for(int i = 0; i < graph[curNode].size(); i++)
        {
            int nextNode = graph[curNode][i].first;
            long long nextDistance = distance + graph[curNode][i].second;

            if(nextDistance < d[nextNode])
            {
                d[nextNode] = nextDistance;
                pq.push({nextDistance, nextNode});
            }
        }

    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    for(int i = 0; i < 1010; i++) d[i] = INF;
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    int from, to; cin >> from >> to;

    Dijkstra(from);
    cout << d[to];
}