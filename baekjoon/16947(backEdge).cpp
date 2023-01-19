#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> edges[3010];
int parent[3010];
bool visited[3010];
bool cycle[3010];
bool foundCycle;
int dist[3010];

void dfs(int node) {
    visited[node] = true;

    for (auto next: edges[node]) {
        if(foundCycle) return;
        // cycle 찾음
        if(visited[next]) {
            if(parent[node] != next) {
                // 사이클에 속한 노드 기록
                cycle[next] = true;
                int cur = node;
                while(cur != next) {
                    cycle[cur] = true;
                    cur = parent[cur];
                }
                foundCycle = true;
                return;
            }
        }
        else {
            parent[next] = node;
            dfs(next);
        }
    }
}

void bfs() {
    memset(visited, false, sizeof(visited));
    queue<pair<int,int>> q;

    for (int node = 1; node <= N; node++) {
        if (cycle[node]) {
            visited[node] = true;
            q.push({node, 0});
        }
    }

    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        dist[cur] = depth;

        for (auto next: edges[cur]) {
            if(visited[next]) continue;
            visited[next] = true;
            q.push({next, depth + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }


    dfs(1);
    bfs();

    for(int i = 1; i <= N; i++) {
        cout << dist[i] << ' ';
    }

}