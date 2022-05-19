#include <iostream>
#include <queue>
#include <vector>
#define INF 10000000
using namespace std;

vector<pair<int,int>> graph[1010];
int N, M, X;

void Dijkstra(int start, vector<int> &d)
{
    d[start] = 0;
    // node, distance
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({start, 0});

    while(!pq.empty())
    {
        int curNode = pq.top().first;
        int curDistance = pq.top().second;
        pq.pop();

        if(curDistance > d[curNode]) continue; //

        for(auto x : graph[curNode])
        {
            int nextNode = x.first;
            int nextDistance = curDistance + x.second;

            if(d[nextNode] > nextDistance)
            {
                d[nextNode] = nextDistance;
                pq.push({nextNode, nextDistance});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    // X 마을에서 다른 마을들로의 최단경로
    vector<int> back(N+1, INF);
    Dijkstra(X, back);

    int answer = 0;
    for(int i = 1; i <= N; i++)
    {
        vector<int> go(N+1, INF);
        Dijkstra(i, go);
        int cost = go[X] + back[i];
        answer = max(answer, cost);
    }
    
    cout << answer;
}