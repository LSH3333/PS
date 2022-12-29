#include <iostream>
#include <vector>
using namespace std;

int N, M;
int target1, target2;
vector<int> edges[110];
bool mark[110];

void dfs(int node1, int node2, int depth) {
    if(node1 == node2) {
        cout << depth;
        exit(0);
    }
    mark[node1] = true;
    for (auto next: edges[node1]) {
        if(mark[next]) continue;
        dfs(next, node2, depth + 1);
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> target1 >> target2;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(target1, target2, 0);
    cout << -1;
}