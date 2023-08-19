#include <iostream>
#include <vector>
using namespace std;

#define MAX 100000
int V;
vector<pair<int,int>> edges[MAX+1];


void GetMostFarNode(int node, int dist, vector<bool> &visited, int &resDist, int &resNode) {
    if(dist > resDist) {
        resDist = dist;
        resNode = node;
    }

    for (const auto &next: edges[node]) {
        if(visited[next.first]) continue;
        visited[next.first] = true;
        GetMostFarNode(next.first, dist+next.second, visited, resDist, resNode);
        visited[next.first] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> V;
    for(int i = 0; i < V; i++) {
        int v, n, edge;
        cin >> v;
        while(true) {
            cin >> n;
            if(n == -1) {
                break;
            }
            cin >> edge;
            edges[v].push_back({n, edge});
        }
    }

    // ?? 1 ?? ?? ? ??? ?? ??
    vector<bool> visited(V, false);
    visited[1] = true;
    int farDist1=0, farNode1=0;
    GetMostFarNode(1, 0, visited, farDist1, farNode1);
    visited[1] = false;
    // ??? ?? ?? ? ?? farNode1 ?? ?? ?? ? ?? farNode2 ??
    visited[farNode1] = true;
    int farDist2=0, farNode2=0;
    GetMostFarNode(farNode1, 0, visited, farDist2, farNode2);
    visited[farNode1] = false;

    // ??1?? ?? ? ?? farNode1, farNode1 ?? ?? ? ?? farNode2 ? ??? ??? ??
    cout << farDist2;

}