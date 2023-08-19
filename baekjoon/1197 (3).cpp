#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10000

int V, E;
vector<pair<int,pair<int,int>>> edges;
int parent[MAX+1];

int GetParent(int n) {
    if(parent[n] == n) return n;
    return parent[n] = GetParent(parent[n]);
}

bool IsParentSame(int n1, int n2) {
    n1 = GetParent(n1);
    n2 = GetParent(n2);
    return n1 == n2;
}

void Union(int n1, int n2) {
    n1 = GetParent(n1);
    n2 = GetParent(n2);
    parent[max(n1, n2)] = min(n1, n2);
}

int Kruskal() {
    int answer = 0;

    for(const auto &x : edges) {
        int n1 = x.second.first, n2 = x.second.second;
        int dist = x.first;

        if (!IsParentSame(n1, n2)) {
            Union(n1, n2);
            answer += dist;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int a,b,c; cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());

    for(int i = 0; i <= V; i++) {
        parent[i] = i;
    }

    cout << Kruskal();
}