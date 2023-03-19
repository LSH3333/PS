#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 10000
#define INF 1000000010

int N, M, A, B;
vector<pair<int,int>> edges[MAX+1];
vector<pair<int,int>> input[MAX+1];
int mark[MAX + 1];

void FindMaxValBridge() {
    for(int i = 1; i <= N; i++) {
        sort(input[i].begin(), input[i].end());
    }

    for(int node = 1; node <= N; node++) {
        if(input[node].empty()) continue;

        int n = input[node].front().first;
        int maxVal = input[node].front().second;
        for (auto x: input[node]) {
            if(x.first != n) {
                edges[node].push_back({n, maxVal});
                n = x.first;
                maxVal = x.second;
            }
            maxVal = max(maxVal, x.second);
        }
        edges[node].push_back({n, maxVal});
    }
}

void bfs() {
    queue<int> q;
    mark[A] = INF;
    q.push(A);

    while (!q.empty()) {
        int curNode = q.front();
        q.pop();

        for (auto next: edges[curNode]) {
            int avail = min(next.second, mark[curNode]);
            if(avail > mark[next.first]) {
                mark[next.first] = avail;
                q.push(next.first);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        input[a].push_back({b, c});
        input[b].push_back({a, c});
    }
    cin >> A >> B;



    FindMaxValBridge();
    bfs();

    cout << mark[B];

}