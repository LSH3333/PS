#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> edges[100001];
int sortOrder[100001];
queue<int> order;
bool visited[100001];

bool cmp(const int &a, const int &b) {
    return sortOrder[a] < sortOrder[b];
}

bool bfs() {
    if(order.front() != 1) return false;
    order.pop();

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next: edges[cur]) {
            if(visited[next]) continue;
            if(next != order.front()) return false;
            q.push(next);
            visited[next] = true;
            order.pop();
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(int i = 1; i <= N; i++) {
        int a; cin >> a;
        sortOrder[a] = i;
        order.push(a);
    }
    for(int i = 1; i <= N; i++) {
        sort(edges[i].begin(), edges[i].end(), cmp);
    }

    cout << bfs();
}