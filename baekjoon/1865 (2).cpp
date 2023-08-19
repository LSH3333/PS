#include <iostream>
#include <queue>
using namespace std;

#define INF 1000000000

struct Info {
    int s, e, t;
};

bool BellmanFord(const vector<Info> &edges, int N, int M, int W) {
    vector<int> d(N+1, INF);
    d[1] = 0;

    // N-1 ? ??
    for(int i = 0; i < N-1; i++) {
        // ?? ?? ??
        for(int j = 0; j < edges.size(); j++) {
            int from = edges[j].s;
            int to = edges[j].e;
            int dist = edges[j].t;

//            if(d[from] == INF) continue;
            int nextDist = d[from] + dist;
            if(d[to] > nextDist) {
                d[to] = nextDist;
            }
        }
    }

    // N ?? ??
    for(int j = 0; j < edges.size(); j++) {
        int from = edges[j].s;
        int to = edges[j].e;
        int dist = edges[j].t;

//        if(d[from] == INF) continue;
        int nextDist = d[from] + dist;
        if(nextDist < d[to]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int N, M, W;
        vector<Info> edges;
        cin >> N >> M >> W;
        for(int i = 0; i < M; i++) {
            int s,e,t; cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        for(int i = 0; i < W; i++) {
            int s, e, t; cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        bool res = BellmanFord(edges, N, M, W);
        if(res) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}