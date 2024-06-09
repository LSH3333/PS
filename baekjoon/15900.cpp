#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, answer;
vector<int> edges[500010];
int visited[500010];

void bfs() {
    queue<pair<int,int>> q;
    q.push({1, 0});

    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        bool isRoot = true;
        for (auto next: edges[cur]) {
            if(next != 1 && visited[next] == 0) {
                isRoot = false;
                visited[next] = depth + 1;
                q.push({next, depth + 1});
            }
        }

        if (isRoot) {
            answer += depth;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    bfs();

    if(answer % 2 == 0) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
}