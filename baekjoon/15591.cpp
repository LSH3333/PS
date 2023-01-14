#include <iostream>
#include <vector>
using namespace std;

#define MAX 5010
#define INF 100000000
int N, Q;
vector<pair<int,int>> edges[MAX];
int mark[MAX][MAX];

void dfs(int startNode, int node, int minVal) {
    mark[startNode][node] = minVal;

    for (auto next: edges[node]) {
        if(mark[startNode][next.first] > 0) continue;
        dfs(startNode, next.first, min(minVal, next.second));
    }
}

void MakeGraph() {
    for(int i = 1; i <= N; i++) {
        dfs(i, i, INF);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    for(int i = 0; i < N-1; i++) {
        int p, q, r; cin >> p >> q >> r;
        edges[p].push_back({q, r});
        edges[q].push_back({p, r});
    }

    MakeGraph();

    for(int i = 0; i < Q; i++) {
        int k, v; cin >> k >> v;
        int cnt = 0;

        for(int j = 1; j <= N; j++) {
            if(mark[v][j] != INF && mark[v][j] >= k) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }

}