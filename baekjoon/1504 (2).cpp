#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 800
#define INF 300000000
int N, E;
vector<pair<int,int>> edges[MAX+1];

struct cmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
        return a.second > b.second;
    }
};

int Dijkstra(int startNode, int goalNode) {
    vector<int> d(N+1, INF);
    d[startNode] = 0;
    // {node,dist}
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({startNode, 0});

    while (!pq.empty()) {
        int cur = pq.top().first;
        int dist = pq.top().second;
        pq.pop();

        if(d[cur] < dist) continue;

        for (const auto &next: edges[cur]) {
            int nextNode = next.first;
            int nextDist = next.second;
            if(d[nextNode] > dist + nextDist) {
                d[nextNode] = dist + nextDist;
                pq.push({nextNode, dist + nextDist});
            }
        }
    }

    if(d[goalNode] == INF) return -1;
    else return d[goalNode];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int midNode1, midNode2;
    cin >> N >> E;
    for(int i = 0; i < E; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    cin >> midNode1 >> midNode2;

    int res1, res2;
    int OneToMid1 = Dijkstra(1, midNode1);
    int Mid1ToMid2 = Dijkstra(midNode1, midNode2);
    int Mid2ToN = Dijkstra(midNode2, N);
    if(OneToMid1 == -1 || Mid1ToMid2 == -1 || Mid2ToN == -1) {
        res1 = INF;
    } else {
        res1 = OneToMid1 + Mid1ToMid2 + Mid2ToN;
    }

    int OneToMid2 = Dijkstra(1, midNode2);
    int Mid2ToMid1 = Dijkstra(midNode2, midNode1);
    int Mid1ToN = Dijkstra(midNode1, N);
    if(OneToMid2 == -1 || Mid2ToMid1 == -1 || Mid1ToN == -1) {
        res2 = INF;
    } else {
        res2 = OneToMid2 + Mid2ToMid1 + Mid1ToN;
    }

    int answer = min(res1, res2);
    if(answer == INF) {
        answer = -1;
    }
    cout << answer;
}