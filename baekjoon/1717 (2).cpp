#include <iostream>
using namespace std;

#define MAX 1000000

int N, M;
int parent[MAX+1];

void Init() {
    for(int i = 0; i < MAX+1; i++) {
        parent[i] = i;
    }
}

int GetParent(int node) {
    if(node == parent[node]) return node;
    return parent[node] = GetParent(parent[node]);
}

bool IsParentSame(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    return node1 == node2;
}

void Union(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    parent[max(node1,node2)] = min(node1,node2);
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Init();
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int op, a, b;
        cin >> op >> a >> b;

        // ??? ??
        if(op == 0) {
            Union(a, b);
        }
            // ??
        else {
            if(IsParentSame(a,b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}