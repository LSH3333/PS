#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int parentNode[10001];

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
    int a = FindParent(node1);
    int b = FindParent(node2);
    if(a < b) parentNode[b] = a;
    else parentNode[a] = b;
}

// node1, node2가 연결되어 있는지
bool Find(int node1, int node2)
{
    int a = FindParent(node1);
    int b = FindParent(node2);
    if(a == b) return true;
    return false;
}

int main()
{
    int V, E; cin >> V >> E;
    vector<vector<int>> costs;
    for(int i = 0; i < E; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        vector<int> tmp = {a, b, c};
        costs.push_back(tmp);
    }

    // 가중치 기준 오름차순 정렬
    sort(costs.begin(), costs.end(), cmp);

    // 최초 모든 노드들의 부모는 자기자신
    for(int i = 0; i <= V; i++) parentNode[i] = i;

    int answer = 0;
    for(auto cost : costs)
    {
        // 두 노드가 연결 안되어 있으면
        if(!Find(cost[0], cost[1]))
        {
            Union(cost[0], cost[1]);
            answer += cost[2];
        }
    }

    cout << answer;
}