#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
bool cycle[3010];
bool cycleNode[3010];
bool markEdge[3010][3010];
vector<int> edges[3010];


bool trigger;
void dfs(int startNode, int node) {
    cycleNode[node] = true;

//    cout << "cur: " << node << "   " << "trigger: " << trigger << endl;
//    Print();

    for (auto next: edges[node]) {
        if(trigger) return;
        if(markEdge[node][next]) continue;
        if(next == startNode) { trigger = true; return; }
        markEdge[node][next] = true;
        markEdge[next][node] = true;
        dfs(startNode, next);
    }

    if(!trigger) cycleNode[node] = false;
}

bool visited[3010];
int CalDist(int startNode) {
    if(cycle[startNode]) return 0;
    queue<pair<int,int>> q;
    memset(visited, false, sizeof(visited));
    q.push({startNode, 0});
    visited[startNode] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        for (auto next: edges[cur]) {
            if(cycle[next]) return depth+1;
            if(visited[next]) continue;
            visited[next] = true;
            q.push({next, depth + 1});
        }
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(int startNode = 1; startNode <= N; startNode++) {
        if(cycle[startNode]) continue;
        trigger = false;
        dfs(startNode, startNode);
        for(int i = 1; i <= N; i++) {
            if(cycleNode[i]) cycle[i] = true;
        }
        memset(markEdge, false, sizeof(markEdge));
    }

    for(int i = 1; i <= N; i++) {
        cout << CalDist(i) << ' ';
    }

}