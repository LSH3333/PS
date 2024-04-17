#include <iostream>
#include <vector>
using namespace std;

int V, E;
vector<int> edges[3001];
bool visitedNode[3001];
bool visitedEdge[3001][3001];
bool possible;

void Init() {
    for(int i = 0; i <= V; i++) {
        visitedNode[i] = false;
        for(int j = 0; j <= V; j++) {
            visitedEdge[i][j] = false;
        }
    }
    possible = false;
}

void dfs(int node, int edgeCnt) {
    if(possible) return;
    visitedNode[node] = true;

    if(edgeCnt == E) {
        possible = true;
        return;
    }

    for (auto next: edges[node]) {
        if (!visitedEdge[node][next]) {
            visitedEdge[node][next] = true;
            visitedEdge[next][node] = true;
            dfs(next, edgeCnt + 1);
        }
    }
}

bool CheckNodes() {
    for(int j = 1; j <= V; j++) {
        if(!visitedNode[j]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(int i = 1; i <= V; i++) {

        dfs(i, 0);
        if (possible && CheckNodes()) {
            cout << "YES";
            return 0;
        }

        Init();
    }

    cout << "NO";
}