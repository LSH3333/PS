#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

#define MAX 50000
#define INF 100000000

int N, M;
vector<pair<int,int>> edges[MAX+1];
int d[MAX+1];

void Dijkstra() {
    d[1] = 0;
    // pair.first 기준 min heap
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if (curDist < d[curNode]) continue;

        for (auto next: edges[curNode]) {
            int nextNode = next.first;
            int nextDist = curDist + next.second;

            if (nextDist < d[nextNode]) {
                d[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    for(int i = 0; i <= N; i++) {
        d[i] = INF;
    }

    Dijkstra();


    cout << d[N];

}
