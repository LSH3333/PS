#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100000
int N, M, answer;
int parent[MAX + 1];

int GetParent(int node) {
    if(node == parent[node]) return node;
    return parent[node] = GetParent(parent[node]);
}

bool IsParentSame(int n1, int n2) {
    return GetParent(n1) == GetParent(n2);
}

void Union(int n1, int n2) {
    n1 = GetParent(n1);
    n2 = GetParent(n2);
    parent[max(n1, n2)] = min(n1, n2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < MAX+1; i++) {
        parent[i] = i;
    }
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int u,v; cin >> u >> v;

        // ?? ???? ??
        if (!IsParentSame(u, v)) {
            Union(u, v);
        }
            // ?? ???? ??
        else {
            answer++;
        }
    }


    for(int i = 1; i <= N; i++) {
        if(parent[i] == i) answer++;
    }

    cout << answer-1;
}