#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int V, E;
int parent[10010];
vector<pair<int,pair<int,int>>> edges;

int GetParent(int node) {
    if (node == parent[node]) {
        return node;
    }

    return parent[node] = GetParent(parent[node]);
}

bool IsParentSame(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    return node1 == node2;
}

void Union(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    parent[max(node1,node2)] = min(node1,node2);
}

int Kruskal() {
    int answer = 0;

    for(auto x : edges) {
        int node1 = x.second.first;
        int node2 = x.second.second;
        int cost = x.first;

        if (!IsParentSame(node1, node2)) {
            answer += cost;
            Union(node1, node2);
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int A, B, C; cin >> A >> B >> C;
        edges.push_back({C,{A,B}});
    }

    // ??? ?? ???? ??
    sort(edges.begin(), edges.end());

    for(int i = 0; i <= V; i++) {
        parent[i] = i;
    }


    cout << Kruskal();
}