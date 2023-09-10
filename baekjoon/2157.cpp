#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<pair<int,int>> edges[301];
int d[301][301];

void bfs() {
    // node, depth
    queue<pair<int,int>> q;
    q.push({1, 1});
    d[1][1] = 0;

    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        if(depth >= M) continue;

        for (auto next: edges[cur]) {
            int nextNode = next.first;
            int nextDist = next.second;

            if (d[nextNode][depth + 1] < d[cur][depth] + nextDist) {
                d[nextNode][depth+1] = d[cur][depth] + nextDist;
                q.push({nextNode, depth + 1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++) {
        int a,b,c; cin >> a >> b >> c;
        if(a > b) continue;
        edges[a].push_back({b, c});
    }

    bfs();

    int answer = 0;
    for(int i = 1; i <= M; i++) {
        answer = max(answer, d[N][i]);
    }
    cout << answer;
}