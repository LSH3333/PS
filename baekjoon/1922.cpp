#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int parentNode[1001];

bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2];
}

int GetParent(int node)
{
    if(node == parentNode[node]) return node;
    return GetParent(parentNode[node]);
}

// 같으면 true return
bool IsParentSame(int node1, int node2)
{
    int p1 = GetParent(node1);
    int p2 = GetParent(node2);
    if(p1 == p2) return true;
    else return false;
}

void Union(int node1, int node2)
{
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    parentNode[node2] = node1;
}

int Kruskal(vector<vector<int>> &costs)
{
    int answer = 0, cnt = 0;
    for(const auto &x : costs)
    {
        int node1 = x[0], node2 = x[1], cost = x[2];
        if(!IsParentSame(node1, node2))
        {
            answer += cost;
            cnt++;
            Union(node1, node2);
        }

        if(cnt == N-1) break;
    }
    return answer;
}

int main()
{
    cin >> N >> M;
    vector<vector<int>> costs(M);
    for(int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        costs[i] = {a, b, c};
    }
    sort(costs.begin(), costs.end(), cmp);
    for(int i = 0; i < 1001; i++) parentNode[i] = i;


    cout << Kruskal(costs);


}