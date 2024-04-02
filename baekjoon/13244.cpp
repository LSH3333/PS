#include <iostream>
#include <vector>
using namespace std;

int T,N,M;
int parent[1010];

int GetParent(int n) {
    if(n == parent[n]) return n;
    return parent[n] = GetParent(parent[n]);
}

bool IsParentSame(int n1, int n2) {
    n1 = GetParent(n1);
    n2 = GetParent(n2);
    return n1 == n2;
}

void Union(int n1, int n2) {
    n1 = GetParent(n1);
    n2 = GetParent(n2);
    parent[max(n1, n2)] = min(n1, n2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> N >> M;

        for(int i = 0; i <= N; i++) {
            parent[i] = i;
        }

        string res = "tree";
        for(int i = 0; i < M; i++) {
            int a,b; cin >> a >> b;

            if (!IsParentSame(a, b)) {
                Union(a, b);
            }
            else {
                res = "graph";
            }
        }

        // check
        int cnt = 0;
        for(int i = 1; i <= N; i++) {
            if(i == GetParent(i)) cnt++;
        }
        if(cnt > 1) {
            res = "graph";
        }

        cout << res << '\n';
    }
}