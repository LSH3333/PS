#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#include <algorithm>

bool mark_dfs[10001];
bool mark_bfs[10001];
vector<int> edge[1001];

void dfs(int n) {
    if(mark_dfs[n] == true) return;

    cout << n << ' ';
    mark_dfs[n] = true;
    for(int x : edge[n]) dfs(x);

}

void bfs(int n) {
    queue<int> q;
    q.push(n);
    mark_bfs[n] = true;
    cout << n << ' ';

    while(!q.empty()) {
        int vertex = q.front();
        for(int x : edge[vertex]) {
            if(mark_bfs[x] == false) {
                cout << x << ' ';
                q.push(x);
                mark_bfs[x] = true;
            }
        }
        q.pop();
    }

}


int main() {
    int V, E, v; // vertex ,edge, starting vertex
    cin >> V >> E >> v;

    for(int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i = 1; i <= V; i++) {
        sort(edge[i].begin(), edge[i].end());
    }

    dfs(v); cout << endl;
    bfs(v);
}