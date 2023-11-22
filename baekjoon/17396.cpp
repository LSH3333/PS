#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100000
#define INF 40000000000

int N, M;
vector<pair<int,long long>> edges[MAX+1];
bool visible[MAX+1];
long long d[MAX+1];

struct cmp {
    bool operator()(const pair<int,long long> &a, const pair<int,long long> &b) {
        return a.second > b.second;
    }
};

void Dijkstra() {
    priority_queue<pair<int,long long>, vector<pair<int,long long>>, cmp> pq;
    pq.push({0, 0});
    d[0] = 0;

    while (!pq.empty()) {
        int curNode = pq.top().first;
        long long totalDist = pq.top().second;
        pq.pop();
//        cout << curNode << ' ' << totalDist << endl;
        if(d[curNode] < totalDist) continue;

        for (const auto &next: edges[curNode]) {
            int nextNode = next.first;
            long long nextDist = next.second;
            // ?? ??? ??? ??? ??? ??? ???? ?? x
            if(nextNode != N-1 && visible[nextNode]) continue;

            if (d[nextNode] > totalDist + nextDist) {
                d[nextNode] = totalDist + nextDist;
                pq.push({nextNode, totalDist + nextDist});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> visible[i];
        d[i] = INF;
    }
    for(int i = 0; i < M; i++) {
        int a,b,c; cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    Dijkstra();

    if(d[N-1] == INF) cout << -1;
    else cout << d[N-1];
}