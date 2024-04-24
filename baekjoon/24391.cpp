#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int parent[100010];
int arr[100010];

void Init() {
    for(int i = 0; i < 100010; i++) {
        parent[i] = i;
    }
}

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
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    Init();

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;

        Union(a, b);
    }

    int answer = 0;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i < N; i++) {
        if (GetParent(arr[i]) != GetParent(arr[i - 1])) {
            answer++;
        }
    }

    cout << answer;
}