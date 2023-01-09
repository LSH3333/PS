#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K, X;
vector<int> edges[300001];
int mark[300001];

void bfs() {
    queue<pair<int,int>> q;
    q.push({X, 0});

    while(!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        for (auto next: edges[cur]) {
            if(mark[next] > 0 || next == X) continue;
            q.push({next, depth + 1});
            mark[next] = depth + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K >> X;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
    }

    bfs();

    bool found = false;
    for(int i = 1; i <= N; i++) {
        if(mark[i] == K) {
            cout << i << '\n';
            found = true;
        }
    }
    if(!found) cout << -1;
}