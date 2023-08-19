#include <iostream>
#include <queue>
using namespace std;

int Topology(int N, int K, int W, vector<int> &cost, vector<vector<int>> &graph,
             vector<int> &inDegree) {
    vector<int> d(N + 1, 0);
    queue<int> q;

    for(int i = 1; i <= N; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
            d[i] = cost[i];
        }
    }

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        for (auto next: graph[n]) {
            d[next] = max(d[next], d[n] + cost[next]);
            inDegree[next]--;
            if(inDegree[next] == 0) {
                q.push(next);
            }
        }
    }

    return d[W];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;

    while(T--) {
        int N, K, W;
        cin >> N >> K;
        vector<int> cost(N+1);
        vector<vector<int>> graph(N+1, vector<int>());
        vector<int> inDegree(N+1, 0);

        for(int i = 1; i <= N; i++) {
            cin >> cost[i];
        }
        for(int i = 0; i < K; i++) {
            int x, y; cin >> x >> y;
            graph[x].push_back(y);
            inDegree[y]++;
        }
        cin >> W;

        cout << Topology(N, K, W, cost, graph, inDegree) << '\n';
    }


}