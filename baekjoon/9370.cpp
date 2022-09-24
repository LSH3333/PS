#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 시작노드 s에서 g까지 + g에서 h까지 + h에서 도착후보지까지 == 시작노드에서 도착후보지까지  면 도착 가능 지점
// 시작노드 s에서 h까지 + h에서 g까지  중 작은것

#define INF 100000000
int N, M, T;
int S, G, H;

void Dijkstra(int startNode, vector<int> &d, const vector<pair<int,int>> edges[])
{
    // distance, node
    priority_queue<pair<int,int>> pq;
    pq.push({0, startNode});
    d[startNode] = 0;

    while (!pq.empty())
    {
        int node = pq.top().second;
        int distance = pq.top().first * -1;
        pq.pop();

        if(d[node] < distance) continue;

        for(auto x : edges[node])
        {
            int nextNode = x.first;
            int nextDistance = distance + x.second;
            if(nextDistance < d[nextNode])
            {
                d[nextNode] = nextDistance;
                pq.push({nextDistance * -1, nextNode});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TC; cin >> TC;
    while(TC--)
    {
        cin >> N >> M >> T >> S >> G >> H;
        vector<pair<int,int>> edges[2010];
        vector<int> candidates(T);
        vector<int> answer;
        for(int i = 0; i < M; i++)
        {
            int a, b, d; cin >> a >> b >> d;
            edges[a].push_back({b, d});
            edges[b].push_back({a, d});
        }
        for(int i = 0; i < T; i++)
        {
            int x; cin >> x;
            candidates[i] = x;
        }

        // 시작노드에서 다른 노드까지 최단 거리
        vector<int> sD(N+1, INF);
        // 노드 g에서 다른 노드까지 최단거리
        vector<int> gD(N+1, INF);
        // 노드 h에서 다른 노드까지 최단거리
        vector<int> hD(N+1, INF);
        Dijkstra(S, sD, edges);
        Dijkstra(G, gD, edges);
        Dijkstra(H, hD, edges);

        for(auto c : candidates)
        {
            // start to candidate
            int sToC = sD[c];
            // s -> g -> h -> c
            int dist1 = sD[G] + gD[H] + hD[c];
            // s -> h -> g -> c
            int dist2 = sD[H] + hD[G] + gD[c];
            // 둘중 작은 값
            int minDist = min(dist1, dist2);

            if(minDist == sToC) answer.push_back(c);
        }
        sort(answer.begin(), answer.end());

        for(auto x : answer) cout << x << ' ';
        cout << '\n';
    }



}