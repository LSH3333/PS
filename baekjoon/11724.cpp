#include <iostream>
using namespace std;
#include <vector>

vector<int> edge[1001];
bool mark[1001];

void dfs(int n) {
    if(mark[n]) return;
    mark[n] = true;
    //cout << n << ' ';

    for(int x : edge[n]) dfs(x);
}

int main() {
    int N, M; // 정점, 간선
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        edge[u].push_back(v);
        edge[v].push_back(u);
    }
/*
    for(int i = 0; i <= M; i++) {
        cout << i << ": ";
        for(int x : edge[i]) cout << x << ' ';
        cout << endl;
    } cout << endl;
*/

    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(!mark[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt;
}