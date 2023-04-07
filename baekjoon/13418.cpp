#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int,pair<int,int>>> edges;
int parent[1010];

int GetParent(int node) {
    if(node == parent[node]) return node;
    return parent[node] = GetParent(parent[node]);
}

bool IsParentSame(int node1, int node2) {
    return GetParent(node1) == GetParent(node2);
}

void Union(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    parent[max(node1,node2)] = min(node1, node2);
}

int Kruskal() {
    int sum = 0, cnt = 0;

    for(auto x : edges) {
        int cost = x.first;
        int node1 = x.second.first, node2 = x.second.second;

        if (!IsParentSame(node1, node2)) {
            Union(node1, node2);
            if(cost == 1)
                sum += cost;
            cnt++;
        }

        if(cnt == N-1) break;
    }

    return sum*sum;
}

void Init() {
    for(int i = 0; i <= N; i++) {
        parent[i] = i;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    N++;
    for(int i = 0; i < M+1; i++) {
        int a, b, c; cin >> a >> b >> c;
        c = c == 0 ? 1 : 0;
        edges.push_back({c, {a, b}});
    }


    Init();
    // 내림 차순
    sort(edges.begin(), edges.end(), greater<>());
    int ans1 = Kruskal();

    Init();
    // 오름 차순
    sort(edges.begin(), edges.end(), less<>());
    int ans2 = Kruskal();

//    cout << ans1 << ' ' << ans2 << endl;
    cout << ans1-ans2;

}