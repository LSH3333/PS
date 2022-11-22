#include <iostream>
#include <vector>
using namespace std;

int N, M;
int parent[1000010];

int FindParent(int node) {
    if(node == parent[node]) return node;
    return parent[node] = FindParent(parent[node]);
}

bool IsParentSame(int node1, int node2) {
    node1 = FindParent(node1);
    node2 = FindParent(node2);
    return node1 == node2;
}

void Union(int node1, int node2) {
    node1 = FindParent(node1);
    node2 = FindParent(node2);
    int maxN = max(node1, node2);
    int minN = min(node1, node2);
    parent[maxN] = minN;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i <= N; i++) {
        parent[i] = i;
    }
    for(int i = 0; i < M; i++) {
        int op, a, b; cin >> op >> a >> b;
        if(op == 0) {
            if(!IsParentSame(a,b)) {
                Union(a,b);
            }
        }
        else {
            if(FindParent(a) == FindParent(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}