#include <iostream>
#include <vector>
using namespace std;

int V;
vector<pair<int,int>> edges[100010];

void dfs(int v, int dist, int &maxDist, int &ansV, vector<bool> &mark)
{
    if(dist > maxDist)
    {
        maxDist = dist;
        ansV = v;
    }

    for(auto next : edges[v])
    {
        if(mark[next.first]) continue;
        mark[next.first] = true;
        dfs(next.first, dist+next.second, maxDist, ansV, mark);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> V;
    for(int i = 1; i <= V; i++)
    {
        int v; cin >> v;
        while(true)
        {
            int num; cin >> num;
            if(num == -1) break;
            else
            {
                int edge; cin >> edge;
                edges[v].push_back({num, edge});
            }
        }
    }

    // 1번 노드에서 가장 먼 노드 a 구함
    int maxDist = 0, a = 0;
    vector<bool> mark(V+1, false);
    mark[1] = true;
    dfs(1, 0, maxDist, a, mark);

    // 노드 a에서 가장 먼 노드 b 구함
    maxDist = 0;
    int b = 0;
    fill(mark.begin(), mark.end(), false);
    mark[a] = true;
    dfs(a, 0, maxDist, b, mark);

    // a-b 의 거리가 트리의 지름
    cout << maxDist;
}