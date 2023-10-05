#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 200000

int N, M;
vector<int> edges[MAX+1];
int ans[MAX+1];

// ?? ??? ??? ? ??? ?? ???
int GetBeliever(int next) {
    int cnt = 0;
    for (auto x: edges[next]) {
        if(ans[x] != -1) {
            cnt++;
        }
    }
    return cnt;
}

void bfs(queue<pair<int,int>> &q) {

    while (!q.empty()) {
        int n = q.front().first;
        int depth = q.front().second;
        q.pop();

        if(ans[n] != -1) {
            ans[n] = min(ans[n], depth);
        } else {
            ans[n] = depth;
        }

        for (auto next: edges[n]) {
            if(ans[next] >= 0) continue;
            int goal = edges[next].size() % 2 == 0 ? (int)edges[next].size() / 2 : (int)edges[next].size() / 2 + 1;

            if(GetBeliever(next) >= goal) {
                q.push({next, depth + 1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    queue<pair<int,int>> q;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        ans[i] = -1;
        while(true) {
            int j; cin >> j;
            if(j == 0) break;
            edges[i].push_back(j);
        }
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        int m; cin >> m;
        q.push({m, 0});
    }

    bfs(q);

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }
}