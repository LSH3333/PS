#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000
int N, M;
vector<pair<int,int>> edges[1010];
int d[1010];
int e[1010];

void Dijkstra() {
    priority_queue<pair<int, int>> pq;
    // distance, node
    pq.push({0, 1});
    d[1] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        for (auto next: edges[cur]) {
            int nextNode = next.first;
            int nextDistance = distance + next.second;

            if (nextDistance < d[nextNode]) {
                d[nextNode] = nextDistance;
                pq.push({-nextDistance, nextNode});
                e[nextNode] = cur;
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a,b,c; cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    for(int i = 0; i < 1010; i++) d[i] = INF;

    Dijkstra();

    vector<pair<int,int>> answer;
    for(int i = 1; i <= N; i++) {
        if(e[i] > 0) {
            answer.push_back({i, e[i]});
        }
    }

    cout << answer.size() << '\n';
    for(auto x : answer) cout << x.first << ' ' << x.second << '\n';

}
