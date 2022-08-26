#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 100000000

pair<int,int> Dijkstra(vector<pair<int,int>> edges[], int startNode, int N)
{
    vector<int> d(N + 1, INF);
    // -distance, node
    priority_queue<pair<int,int>> pq;
    d[startNode] = 0;
    pq.push({0, startNode});

    while(!pq.empty())
    {
        int distance = pq.top().first * -1;
        int node = pq.top().second;
        pq.pop();

        if(distance > d[node]) continue;

        for(auto next : edges[node])
        {
            int nextNode = next.first;
            int nextDistance = next.second + distance;

            if(nextDistance < d[nextNode])
            {
                pq.push({-nextDistance, nextNode});
                d[nextNode] = nextDistance;
            }
        }
    }

    int cnt = 0;
    int maxVal = 0;
    for(int i = 1; i <= N; i++)
    {
        if(d[i] == INF) continue;
        cnt++;
        maxVal = max(maxVal, d[i]);
    }
    return {cnt, maxVal};
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while(T--)
    {
        int N, D, C; cin >> N >> D >> C;
        // node, distance
        vector<pair<int,int>> edges[N+1];
        for(int i = 0; i < D; i++)
        {
            int a, b, s; cin >> a >> b >> s;
            edges[b].push_back({a, s});
        }

        pair<int,int> res = Dijkstra(edges, C, N);
        cout << res.first << ' ' << res.second << '\n';
    }


}