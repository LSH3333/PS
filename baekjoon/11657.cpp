#include <iostream>
#include <vector>
using namespace std;

#define INF 2000000000
int N, M;
long long d[510];

bool BellmanFord(const vector<pair<pair<int,int>,int>> &edges)
{
    d[1] = 0;
    // N-1번 반복
    for(int i = 0; i < N-1; i++)
    {
        // 모든 간선에 대하여
        for(int j = 0; j < M; j++)
        {
            int from = edges[j].first.first;
            int to = edges[j].first.second;
            int dist = edges[j].second;

            if(d[from] == INF) continue; // 한번도 거치지 않은 정점 제외
            long long nextDist = d[from] + dist;
            if(nextDist < d[to]) d[to] = nextDist;
        }
    }

    // N번째
    for(int j = 0; j < M; j++)
    {
        int from = edges[j].first.first;
        int to = edges[j].first.second;
        int dist = edges[j].second;

        if(d[from] == INF) continue; // 한번도 거치지 않은 정점 제외
        long long nextDist = d[from] + dist;
        if(nextDist < d[to]) // 더 작은 값이 된다는 것은 음의 사이클 존재
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    vector<pair<pair<int,int>,int>> edges;
    for(int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({{a,b},c});
    }
    for(int i = 0; i <= N; i++) d[i] = INF;

    if(BellmanFord(edges))
    {
        for(int i = 2; i <= N; i++)
        {
            if(d[i] == INF) cout << -1 << '\n';
            else cout << d[i] << '\n';
        }
    }
    else
    {
        cout << -1;
    }
}