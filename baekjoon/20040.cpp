#include <iostream>
using namespace std;

int N, M;
int parent[500010];

int GetParent(int node) {
    if(parent[node] == node) return node;
    return parent[node] = GetParent(parent[node]);
}

void Union(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    parent[max(node1,node2)] = min(node1, node2);
}

bool IsParentSame(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    return node1 == node2;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    bool end = false;
    for(int i = 1; i <= M; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        if(!IsParentSame(node1, node2)) {
            Union(node1, node2);
        }
        else {
            cout << i;
            end = true;
            break;
        }
    }

    if(!end) {
        cout << 0;
    }
}