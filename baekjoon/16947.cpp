#include <iostream>
#include <vector>
using namespace std;

int N;
bool cycleNode[3010];
vector<int> edges[3010];
// 방문한적 없는 엣지를 거쳐서, 방문한적 있는 노드에 도달한 경우 -> 사이클

void Print() {
    for(int i = 1; i <= N; i++) {
        cout << cycleNode[i] << ' ';
    } cout << endl;
}

bool trigger;
void dfs(int startNode, int node) {
    cout << "cur: " << node << endl;
    Print();
    for (auto next: edges[node]) {
        if (next != startNode && !cycleNode[next]) {
            cycleNode[next] = true;
            dfs(startNode, next);
        }
        if(next == startNode) {
            return;
        }
    }

    cycleNode[node] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(4, 4);



}