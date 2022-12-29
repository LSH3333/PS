#include <iostream>
#include <vector>
using namespace std;

int N, M;
int nodeDepth[50010];
vector<int> edges[50010];
int toParent[50010];


void CheckDepth(int node, int depth) {
    nodeDepth[node] = depth;
    for (auto next: edges[node]) {
        if(nodeDepth[next] > 0) continue;
        toParent[next] = node;
        CheckDepth(next, depth + 1);
    }
}

int FindLCA(int node1, int node2) {
    int deepNode, shallowNode;
    if(nodeDepth[node1] > nodeDepth[node2]) {
        deepNode = node1;
        shallowNode = node2;
    }
    else {
        deepNode = node2;
        shallowNode = node1;
    }

    // 두 노드를 같은 깊이로 맞춤
    int cnt = nodeDepth[deepNode] - nodeDepth[shallowNode];
    while(cnt > 0) {
        deepNode = toParent[deepNode];
        cnt--;
    }

    while(true) {
        if(shallowNode == deepNode) {
            return shallowNode;
        }
        shallowNode = toParent[shallowNode];
        deepNode = toParent[deepNode];
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

    CheckDepth(1, 1);
    
    cin >> M;
    for(int i = 0; i < M; i++) {
        int n1, n2; cin >> n1 >> n2;
        cout << FindLCA(n1, n2) << '\n';
    }
}