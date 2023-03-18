#include <iostream>
#include <vector>
using namespace std;

#define MAX 100000

int N, A, B;
// 노드 i가 연결된 노드는 pair.first, 가중치 pair.second
vector<pair<int,int>> edges[MAX+1];
bool visited[MAX+1];
vector<int> answers;

void dfs(int node) {
    visited[node] = true;
    if(node == B) {
        // 정답
        int maxEdge = 0, sumEdge = 0;
        for(auto edge : answers) {
            maxEdge = max(maxEdge, edge);
            sumEdge += edge;
        }

        cout << sumEdge - maxEdge;

        exit(0);
    }

    for (auto next: edges[node]) {
        int nextNode = next.first;
        int dist = next.second;

        if(!visited[nextNode]) {
            answers.push_back(dist);
            dfs(nextNode);
            answers.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> A >> B;
    for(int i = 0; i < N-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    dfs(A);

}