#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int parent[10001];
bool mark[100001];

void dfs(int node) {
    if(node == 0) return;
    mark[node] = true;
    dfs(parent[node]);
}

int dfs2(int node) {
    if(node == 0) return 0;
    if(mark[node]) return node;
    return dfs2(parent[node]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;

    while(T--) {
        memset(parent, 0, sizeof(parent));
        memset(mark, false, sizeof(mark));

        int N;
        int node1, node2;
        cin >> N;
        for(int i = 0; i < N-1; i++) {
            int a, b; cin >> a >> b;
            parent[b] = a;
        }
        cin >> node1 >> node2;

        dfs(node1);
        cout << dfs2(node2) << '\n';
    }


}