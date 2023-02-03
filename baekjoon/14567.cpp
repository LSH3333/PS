#include <iostream>
#include <queue>
using namespace std;

int N, M;
int entry[1010];
vector<int> edges[1010];
int d[1010];

void TopologySort() {
    queue<pair<int,int>> q;
    for(int i = 1; i <= N; i++) {
        if(entry[i] == 0) q.push({i, 1});
    }

    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        d[cur] = depth;
        for (auto next: edges[cur]) {
            entry[next]--;

            if(entry[next] == 0) {
                q.push({next, depth + 1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        entry[b]++;
        edges[a].push_back(b);
    }

    TopologySort();

    for(int i = 1; i <= N; i++) {
        cout << d[i] << ' ';
    }



}