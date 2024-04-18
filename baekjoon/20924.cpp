#include <iostream>
#include <vector>
using namespace std;

int N, R, G;
int G_Dist, B_Dist;
vector<pair<int,int>> edges[200001];
int visited[200001];


void FindGiga(int node, int prev, int distance) {
    G = node;
    G_Dist = distance;
    visited[node] = true;
    if(edges[node].size() > 2) {
        return;
    }

    for (auto next: edges[node]) {
        int nextNode = next.first;
        int d = next.second;
        if(nextNode == prev) continue;
        FindGiga(nextNode, node, distance + d);
    }
}

void FindBranch(int node, int prev, int distance) {
    B_Dist = max(B_Dist, distance);

    for (auto next: edges[node]) {
        int nextNode = next.first;
        int d = next.second;
        if(nextNode == prev || visited[nextNode]) continue;
        FindBranch(nextNode, node, distance + d);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> R;
    for(int i = 0; i < N-1; i++) {
        int a,b,d;
        cin >> a >> b >> d;
        edges[a].push_back({b, d});
        edges[b].push_back({a, d});
    }

    if(edges[R].size() >= 2) {
        G = R;
        G_Dist = 0;
        FindBranch(G, -1, 0);
    } else {
        FindGiga(R, -1, 0);
        FindBranch(G, -1, 0);
    }
    cout << G_Dist << ' ' << B_Dist;
}