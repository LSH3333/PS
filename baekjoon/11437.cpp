#include <iostream>
#include <vector>
using namespace std;

int N, M;
int nodeDepth[50010];
vector<int> toChild[50010];
int toParent[50010];

void CheckDepth(int node, int depth) {
    nodeDepth[node] = depth;
    for (auto next: toChild[node]) {
        if(nodeDepth[next] > 0) continue;
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
    vector<pair<int, int>> input;
    for(int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        if(a == 1 || b == 1) {
            if(a == 1) {
                toChild[a].push_back(b);
                toParent[b] = a;
            }
            else {
                toChild[b].push_back(a);
                toParent[a] = b;
            }
        }
        else {
            input.push_back({a, b});
        }
    }

    for(int i = 0; i < input.size(); i++) {
        int a = input[i].first, b = input[i].second;
        // a가 부모
        if(toParent[a] > 0) {
            toChild[a].push_back(b);
            toParent[b] = a;
        }
        // b가 부모
        else {
            toChild[b].push_back(a);
            toParent[a] = b;
        }
    }

    CheckDepth(1, 1);

    cin >> M;
    for(int i = 0; i < M; i++) {
        int n1, n2; cin >> n1 >> n2;
        cout << FindLCA(n1, n2) << '\n';
    }
}