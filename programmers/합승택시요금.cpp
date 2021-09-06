#include <string>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;

vector<pair<int,int>> v[210];

void MakeGraph(vector<vector<int>> fares)
{
    for(int i = 0; i < fares.size(); i++)
    {
        int start = fares[i][0];
        int end = fares[i][1];
        int cost = fares[i][2];

        v[start].push_back({end,cost});
        v[end].push_back({start,cost});
    }
}

void dijkstra(int start, vector<int> &d)
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

        for(int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i].first;
            int nextDistance = distance + v[current][i].second;

            if(nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push({next, -nextDistance});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    answer = 1000000000;

    vector<int> S(210, INF);

    MakeGraph(fares);

    // 시작지점 -> 각 정점 최소 비용
    dijkstra(s,S);

    for(int i = 1; i <= n; i++)
    {
        vector<int> D(210, INF);


        dijkstra(i, D);

        int togetherCost = S[i];
        int ACost = D[a];
        int BCost = D[b];
        int total = togetherCost + ACost + BCost;

        answer = min(answer, total);
    }

    return answer;
}