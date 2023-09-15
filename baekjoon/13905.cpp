#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000
int N, M, S, E;
int d[100001];
vector<pair<int,int>> edges[100001];

void Dijkstra() {
    queue<int> q;
    q.push(S);
    d[S] = INF;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (const auto &next: edges[cur]) {
            int nextNode = next.first;
            int k = next.second;

            if(d[nextNode] < min(k, d[cur])) {
                d[nextNode] = min(k, d[cur]);
                q.push(nextNode);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> S >> E;
    for(int i = 0; i < M; i++) {
        int h1, h2, k;
        cin >> h1 >> h2 >> k;
        edges[h1].push_back({h2, k});
        edges[h2].push_back({h1, k});
    }

    Dijkstra();

    cout << d[E];
}