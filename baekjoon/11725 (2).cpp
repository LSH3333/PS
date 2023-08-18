#include <iostream>
#include <vector>
using namespace std;

int N;
int parent[100001];
vector<int> edges[100001];

void dfs(int node) {
    for (const auto &next: edges[node]) {
        if(parent[next] > 0) continue;
        parent[next] = node;
        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1);

    for(int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }
}