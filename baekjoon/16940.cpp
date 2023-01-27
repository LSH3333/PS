#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> edges[100001];
bool visited[100001];
queue<int> order;

bool FindNext(vector<int> &nextNodes) {
    for (auto x: nextNodes) {
        if(x == order.front()) return true;
    }
    return false;
}

bool bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;
    order.pop();

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        vector<int> nextNodes;
        for (auto x: edges[cur]) {
            if(visited[x]) continue;
            nextNodes.push_back(x);
        }

        int cnt = (int)nextNodes.size();
        while(cnt--) {
            bool res = FindNext(nextNodes);
            if(res) {
                visited[order.front()] = true;
                q.push(order.front());
                order.pop();
            }
            else {
                return false;
            }
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
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        order.push(a);
    }

    cout << bfs();
}