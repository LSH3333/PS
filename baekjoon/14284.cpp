#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 100000000
#define MAX 5000
int N, M, S, T;
vector<pair<int,int>> edges[MAX+1];

struct cmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
        return a.second > b.second;
    }
};

int Dijkstra() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    vector<int> d(N+1, INF);
    d[S] = 0;
    pq.push({S, 0});

    while (!pq.empty()) {
        int cur = pq.top().first;
        int dist = pq.top().second;
        pq.pop();

        if(dist > d[cur]) continue;

        for (const auto &next: edges[cur]) {
            int nextNode = next.first;
            int nextDist = next.second;
            if(d[nextNode] > dist + nextDist) {
                d[nextNode] = dist + nextDist;
                pq.push({nextNode, dist + nextDist});
            }
        }
    }

    return d[T];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a,b,c; cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    cin >> S >> T;

    cout << Dijkstra();
}