#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100

int V, E;
vector<int> edges[MAX+1];
bool visited[MAX+1];

int bfs(int _n) {
    int ret = 0;
    queue<int> q;

    q.push(_n);
    visited[_n] = true;

    while (!q.empty()) {
        int n = q.front();
        ret++;
        q.pop();

        for (auto next: edges[n]) {
            if(visited[next]) continue;
            q.push(next);
            visited[next] = true;
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    cout << bfs(1)-1;
}