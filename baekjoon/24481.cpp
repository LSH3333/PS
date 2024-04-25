#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, R;
vector<int> edges[100010];
int d[100010];

void dfs(int node, int depth) {

    for (auto next: edges[node]) {
        if(d[next] == -1) {
            d[next] = depth + 1;
            dfs(next, depth + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> R;
    for(int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for(int i = 1; i <= N; i++) {
        d[i] = -1;
        sort(edges[i].begin(), edges[i].end());
    }


    d[R] = 0;
    dfs(R, 0);

    for(int i = 1; i <= N; i++) {
        cout << d[i] << '\n';
    }
}