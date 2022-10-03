#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 200001

// 집의 수, 길의 수
int M, N;
int parentNode[MAX];

bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2];
}

int FindParent(int node)
{
    if(parentNode[node] == node) return node;
    return parentNode[node] = FindParent(parentNode[node]);
}

bool IsParentSame(int node1, int node2)
{
    node1 = FindParent(node1);
    node2 = FindParent(node2);

    if(node1 == node2) return true;
    else return false;
}

void Union(int node1, int node2)
{
    node1 = FindParent(node1);
    node2 = FindParent(node2);
    parentNode[node2] = node1;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    while(true)
    {
        cin >> M >> N;
        if(M == 0 && N == 0) break;
        vector<vector<int>> edges;
        int allCost = 0;
        for(int i = 0; i < M; i++)
        {
            parentNode[i] = i;
        }
        for(int i = 0; i < N; i++)
        {
            int a, b, c; cin >> a >> b >> c;
            edges.push_back({a,b,c});
            allCost += c;
        }
        sort(edges.begin(), edges.end(), cmp);

        int totalCost = 0;
        for(auto x : edges)
        {
            int node1 = x[0], node2 = x[1], cost = x[2];

            if(!IsParentSame(node1, node2))
            {
                Union(node1, node2);
                totalCost += cost;
            }
        }

        cout << allCost - totalCost << '\n';
    }


}