#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int parentNode[100010];

bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2];
}

int FindParent(int node)
{
    if(node == parentNode[node]) return node;
    return parentNode[node] = FindParent(parentNode[node]);
}

void Union(int node1, int node2)
{
    node1 = FindParent(node1);
    node2 = FindParent(node2);
    parentNode[node2] = node1;
}

// MST의 가중치합, 간선 중 가중치 가장 큰 값 리턴
pair<int,int> Kruskal(const vector<vector<int>> &costs)
{
    for(int i = 0; i < 100010; i++) parentNode[i] = i;

    int maxCost = 0;
    int totalCost = 0;
    for(const auto &x : costs)
    {
        int node1 = x[0], node2 = x[1], cost = x[2];
        // no cycle
        if(FindParent(node1) != FindParent(node2))
        {
            maxCost = max(maxCost, cost);
            totalCost += cost;
            Union(node1, node2);
        }
    }
    return {totalCost, maxCost};
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    vector<vector<int>> costs(M);
    for(int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        costs[i] = {a, b, c};
    }
    sort(costs.begin(), costs.end(), cmp);

    pair<int,int> res = Kruskal(costs);
    cout << res.first - res.second;

}