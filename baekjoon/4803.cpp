#include <iostream>
#include <vector>
using namespace std;

int parentNode[510];
vector<int> edges[510];

int GetParent(int node) {
    if(node == parentNode[node]) return node;
    return parentNode[node] = GetParent(parentNode[node]);
}

bool IsParentSame(int node1, int node2) {
    if(GetParent(node1) == GetParent(node2)) return true;
    else return false;
}

void Union(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    parentNode[max(node1,node2)] = min(node1, node2);
}

void dfs(int node, vector<bool> &mark) {
    mark[node] = true;
    for (auto next: edges[node]) {
        if(mark[next]) continue;
        dfs(next, mark);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    while(true) {
        int N, M;
        vector<pair<int,int>> v;
        cin >> N >> M;
        T++;
        if(N == 0 && M == 0) break;
        for(int i = 0; i <= N; i++) {
            parentNode[i] = i;
            edges[i].clear();
        }

        for(int i = 0; i < M; i++) {
            int node1, node2; cin >> node1 >> node2;
            v.push_back({node1, node2});
            edges[node1].push_back(node2);
            edges[node2].push_back(node1);
        }

        // true : graph, false : tree
        vector<bool> mark(N+1, false);
        for(int i = 0; i < M; i++) {
            int node1 = v[i].first, node2 = v[i].second;

            if(IsParentSame(node1, node2)) {
                // graph
                dfs(node1, mark);
            }
            else {
                Union(node1, node2);
            }
        }

        int treeCnt = 0;
        vector<bool> visited(N+1, false);
        for(int i = 1; i <= N; i++) {
            if(visited[i] || mark[i]) continue;
            dfs(i, visited);
            treeCnt++;
        }

        cout << "Case " << T << ": ";
        if(treeCnt == 0) {
            cout << "No trees.\n";
        }
        else if(treeCnt == 1) {
            cout << "There is one tree.\n";
        }
        else {
            cout << "A forest of " << treeCnt << " trees.\n";
        }
    }

}