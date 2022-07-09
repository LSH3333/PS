#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 200000000
int N, E;
vector<pair<int,int>> costs[810];

// start 정점부터 end 정점 최단거리 구함, 만약 도달 불가능하다면 -1 리턴함
int Dijkstra(int start, int end)
{
    int d[810];
    for(int i = 0; i < 810; i++) d[i] = INF;
    d[start] = 0;
    
    // distance, node
    priority_queue<pair<int,int>> pq;
    pq.push({0, start});

    while(!pq.empty())
    {
        int cur = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if(d[cur] < distance) continue;

        for(int i = 0; i < costs[cur].size(); i++)
        {
            int nextNode = costs[cur][i].first;
            int nextDistance = distance + costs[cur][i].second;

            if(nextDistance < d[nextNode])
            {
                d[nextNode] = nextDistance;
                pq.push({-nextDistance, nextNode});
            }
        }
    }

    if(d[end] == INF) return -1;
    else return d[end];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> E;
    for(int i = 0; i < E; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        costs[a].push_back({b,c});
        costs[b].push_back({a,c});
    }
    int passNode1, passNode2; cin >> passNode1 >> passNode2;

    int ans1;
    int startToPass1 = Dijkstra(1, passNode1);
    int pass1ToPass2 = Dijkstra(passNode1, passNode2);
    int pass2ToEnd = Dijkstra(passNode2, N);
    if(startToPass1 == -1 || pass1ToPass2 == -1 || pass2ToEnd == -1) ans1 = INF;
    else ans1 = startToPass1 + pass1ToPass2 + pass2ToEnd;

    int ans2;
    int startToPass2 = Dijkstra(1, passNode2);
    int pass2ToPass1 = Dijkstra(passNode2, passNode1);
    int pass1ToEnd = Dijkstra(passNode1, N);
    if(startToPass2 == -1 || pass2ToPass1 == -1 || pass1ToEnd == -1) ans2 = INF;
    else ans2 = startToPass2 + pass2ToPass1 + pass1ToEnd;

    if(ans1 == INF && ans2 == INF) cout << -1;
    else cout << min(ans1, ans2);
}