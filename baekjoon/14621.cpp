#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000

int N, M;
char nodeSex[MAX + 1];
vector<pair<int, pair<int,int>>> edges;
int parent[MAX+1];

int GetParent(int node) {
    if(node == parent[node]) return node;
    return parent[node] = GetParent(parent[node]);
}

void Union(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    parent[max(node1, node2)] = min(node1, node2);
}

bool IsParentSame(int node1, int node2) {
    return GetParent(node1) == GetParent(node2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> nodeSex[i];
    }
    for (int i = 0; i < M; i++) {
        int u,v,d; cin >> u >> v >> d;
        edges.push_back({d, {u, v}});
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    int answer = 0, connected = 0;
    for(auto x : edges) {
        int dist = x.first, node1 = x.second.first, node2 = x.second.second;

        if (nodeSex[node1] != nodeSex[node2] &&
            !IsParentSame(node1, node2)) {
            Union(node1, node2);
            answer += dist;
            connected++;
        }

        if(connected == N-1) break;
    }

    if(connected == N-1) {
        cout << answer;
    }
    else {
        cout << -1;
    }


}