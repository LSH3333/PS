#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
int parentNode[1001];
pair<int,int> cord[1001];

double CalDist(int node1, int node2)
{
    double a = pow((cord[node1].first - cord[node2].first),2);
    double b = pow((cord[node1].second - cord[node2].second), 2);
    return sqrt(a+b);
}

void MakeEdges(vector<pair<double, pair<int,int>>> &v)
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = i+1; j <= N; j++)
        {
            v.push_back({CalDist(i, j), {i, j}});
        }
    }
}

int GetParent(int node)
{
    if(node == parentNode[node]) return node;
    return parentNode[node] = GetParent(parentNode[node]);
}

bool IsParentSame(int node1, int node2)
{
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    if(node1 != node2) return false;
    else return true;
}

void Union(int node1, int node2)
{
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    parentNode[max(node1,node2)] = min(node1, node2);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        int x,y; cin >> x >> y;
        cord[i] = {x,y};
        parentNode[i] = i;
    }
    vector<pair<double, pair<int,int>>> v;
    MakeEdges(v);
    sort(v.begin(), v.end());

    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        Union(a, b);
    }

    // Kruskal
    double answer = 0;
    for(auto x : v)
    {
        double dist = x.first;
        int node1 = x.second.first, node2 = x.second.second;

        if(!IsParentSame(node1, node2))
        {
            answer += dist;
            Union(node1, node2);
        }
    }

    printf("%.2f", answer);
}