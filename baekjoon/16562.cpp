#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int parent[10001];

int GetParent(int node)
{
    if(node == parent[node]) return node;
    return parent[node] = GetParent(parent[node]);
}

bool IsParentSame(int node1, int node2)
{
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    if(node1 == node2) return true;
    else return false;
}

void Union(int node1, int node2)
{
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    parent[max(node1, node2)] = min(node1, node2);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    vector<pair<int,int>> costs;
    for(int i = 1; i <= N; i++)
    {
        int cost; cin >> cost;
        costs.push_back({cost, i});
        parent[i] = i;
    }
    sort(costs.begin(), costs.end());

    int sum = 0;
    int edgeCnt = 0;
    for(int i = 0; i < M; i++)
    {
        int v, w; cin >> v >> w;
        if(!IsParentSame(v, w))
        {
            Union(v,w);
            edgeCnt++;
        }
    }

    for(auto x : costs)
    {
        int cost = x.first;
        int node = x.second;

        if(sum + cost > K) break;

        if (!IsParentSame(0, node))
        {
            Union(0, node);
            edgeCnt++;
            sum += cost;
        }
    }

    if(edgeCnt >= N) cout << sum;
    else cout << "Oh no";
}