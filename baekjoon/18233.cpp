#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 5000
#define INF 100000000
int V, E, P;
// {dist, node}
vector<pair<int, int>> edges[MAX + 1];

struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

int Dijkstra(int sn, int en) {
    // {node, dist}, second 기준 min-heap
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    vector<int> d(V + 1, INF);
    pq.push({sn, 0});
    d[sn] = 0;

    while (!pq.empty()) {
        int n = pq.top().first;
        int dist = pq.top().second;
        pq.pop();

        if(d[n] < dist) continue;

        for (auto next: edges[n]) {
            int nextDist = dist + next.first;
            if (d[next.second] > nextDist) {
                d[next.second] = nextDist;
                pq.push({next.second, nextDist});
            }
        }
    }

    return d[en];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E >> P;
    for(int i = 0; i < E; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back({c, b});
        edges[b].push_back({c, a});
    }

    for(int i = 1; i <= V; i++) {
        sort(edges[i].begin(), edges[i].end());
    }


    if (Dijkstra(1, V) >= Dijkstra(1, P) + Dijkstra(P, V)) {
        cout << "SAVE HIM";
    } else {
        cout << "GOOD BYE";
    }
}