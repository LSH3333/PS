#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int parent[110];

struct Pos
{
    double r, c;
};

double GetDist(Pos p1, Pos p2)
{
    return sqrt((p1.r - p2.r) * (p1.r - p2.r) + (p1.c - p2.c) * (p1.c - p2.c));
}

int GetParent(int node)
{
    if(node == parent[node]) return parent[node];
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
    parent[node2] = node1;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;

    vector<Pos> stars(N);
    vector<pair<double, pair<int,int>>> edges;

    for(int i = 0; i < N; i++)
    {
        double r, c; cin >> r >> c;
        Pos star{r,c};
        stars[i] = star;
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            double dist = GetDist(stars[i], stars[j]);
            edges.push_back({dist, {i, j}});
        }
    }

    for(int i = 0; i < N; i++) parent[i] = i;
    sort(edges.begin(), edges.end());


    double answer = 0;
    for(auto edge : edges)
    {
        int node1 = edge.second.first;
        int node2 = edge.second.second;
        double dist = edge.first;

        if(!IsParentSame(node1, node2))
        {
            Union(node1, node2);
            answer += dist;
        }
    }

    printf("%.2f", answer);

}