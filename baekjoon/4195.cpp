#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define MAX 200010

int parent[MAX];
int cnt[MAX];

void Init() {
    for(int i = 0; i < MAX; i++) {
        parent[i] = i;
        cnt[i] = 1;
    }
}

int GetParent(int node) {
    if(parent[node] == node) return node;
    return parent[node] = GetParent(parent[node]);
}

bool IsParentSame(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    return node1 == node2;
}

int Union(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    int minNode = min(node1, node2);
    int maxNode = max(node1, node2);
    cnt[minNode] += cnt[maxNode];
    cnt[maxNode] = 0;
    parent[maxNode] = minNode;
    return cnt[minNode];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;

    while(T--) {
        Init();
        int N;
        // name, idx
        map<string, int> m;
        cin >> N;
        vector<pair<string,string>> input(N);
        int mIdx = 1;
        for(int i = 0; i < N; i++) {
            string n1, n2; cin >> n1 >> n2;
            input[i] = {n1, n2};
            if(m[n1] == 0) m[n1] = mIdx++;
            if(m[n2] == 0) m[n2] = mIdx++;
        }

        for(const auto &x : input) {
            string name1 = x.first, name2 = x.second;
            int n1 = m[name1], n2 = m[name2];

            if(!IsParentSame(n1, n2)) {
                int res = Union(n1, n2);
                cout << res << '\n';
            }
            else {
                cout << cnt[min(GetParent(n1), GetParent(n2))] << '\n';
            }
        }
    }

}