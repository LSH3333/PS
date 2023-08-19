#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000
#define INF 100000000

int N, M, X;
// {node, dist}
vector<pair<int,int>> edges[MAX+1];
int answer;

struct cmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
        return a.first > b.first;
    }
};

void Dijkstra(int startNode, vector<int> &d) {
    // dist ?? min heap
    // dist, node
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({0, startNode});
    d[startNode] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if(d[cur] < dist) continue;

        for (const auto &next: edges[cur]) {
            int nextNode = next.first;
            int nextDist = dist + next.second;
            if(d[nextNode] > nextDist) {
                d[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }

    vector<int> back(N+1, INF);
    Dijkstra(X, back);

    for(int i = 1; i <= N; i++) {
        vector<int> go(N+1, INF);
        Dijkstra(i, go);
        int res = go[X] + back[i];
        answer = max(answer, res);
    }

    cout << answer;
}