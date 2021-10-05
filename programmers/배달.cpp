#include <iostream>
#include <vector>
#include <queue>
#define INF 200000000
using namespace std;

void MakeGraph(vector<vector<int>> road, vector<pair<int,int>> graph[])
{
    for(int i = 0; i < road.size(); i++)
    {
        int start = road[i][0];
        int end = road[i][1];
        int cost = road[i][2];

        graph[start].push_back({end,cost});
        graph[end].push_back({start,cost});
    }
}

void Dijkstra(int start, vector<int> &d, vector<pair<int,int>> graph[])
{
    d[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({start,0});

    while(!pq.empty())
    {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();

        if(d[current] < distance) continue;

        for(int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].first;
            int nextDistance = distance + graph[current][i].second;

            if(nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push({next, -nextDistance});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<pair<int,int>> graph[N+1];
    MakeGraph(road, graph);

    vector<int> D(N+1, INF);
    Dijkstra(1, D, graph);

    for(int i = 1; i <= N; i++)
    {
        if(D[i] <= K) answer++;
    }

    return answer;
}