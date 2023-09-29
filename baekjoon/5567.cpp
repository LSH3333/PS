#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 10000000
int N, M, answer;
vector<int> edges[501];
int d[501];

void Dijkstra() {
    queue<pair<int,int>> q;
    q.push({1, 0});
    d[1] = 0;

    while (!q.empty()) {
        int cur = q.front().first, depth = q.front().second;
        q.pop();

        for (auto next: edges[cur]) {
            if(d[next] > depth+1) {
                d[next] = depth+1;
                q.push({next, depth + 1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(d, d+501, INF);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    Dijkstra();

    for(int i = 2; i <= N; i++) {
        if(d[i] <= 2) {
            answer++;
        }
    }

    cout << answer;
}