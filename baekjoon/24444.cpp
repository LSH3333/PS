#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100000
int N, M, R;
vector<int> edges[MAX+1];
int answer[MAX+1];

void bfs() {
    queue<int> q;
    int depth = 1;
    q.push(R);
    answer[R] = depth++;

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        for (auto next: edges[n]) {
            if(answer[next] > 0) continue;
            answer[next] = depth++;
            q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> R;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        sort(edges[i].begin(), edges[i].end());
    }

    bfs();

    for(int i = 1; i <= N; i++) {
        cout << answer[i] << '\n';
    }

}