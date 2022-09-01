#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 200000000
int N, M;
vector<pair<int,int>> edges[1010];
int d[1010];

void Dijkstra(int startNode, int endNode)
{
    for(int i = 0; i <= N; i++) d[i] = INF;

    vector<int> minDisNodes;
    // distance, node
    priority_queue<pair<int, vector<int>>> pq;
    pq.push({0, {startNode}});
    d[startNode] = 0;

    while (!pq.empty())
    {
        int distance = pq.top().first * -1;
        vector<int> nodes = pq.top().second;
        int node = nodes.back();
        pq.pop();
        

        if(d[node] < distance) continue;

        for (auto next: edges[node])
        {
            int nextNode = next.first;
            int nextDistance = d[node] + next.second;

            if (nextDistance < d[nextNode])
            {
                d[nextNode] = nextDistance;
                nodes.push_back(nextNode);
                pq.push({-nextDistance, nodes});
                nodes.pop_back();

                if(nextNode == endNode)
                {
                    minDisNodes = nodes;
                }
            }
        }
    }
    
    cout << d[endNode] << '\n';
    minDisNodes.push_back(endNode);
    cout << minDisNodes.size() << '\n';
    for(auto x : minDisNodes) cout << x << ' ';
}

int main()
{
    int startNode, endNode;
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back({b,c});
    }
    cin >> startNode >> endNode;

    Dijkstra(startNode, endNode);
}