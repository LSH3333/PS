#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100000
int N, M;
vector<pair<long long,pair<int,int>>> edges;
int parent[MAX+1];

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
    parent[max(n1,n2)] = min(n1,n2);
}

long long Kruskal() {
    long long mstWeight = 0;
    int connected = 0;

    for(const auto &x : edges) {
        long long dist = x.first;
        int n1 = x.second.first, n2 = x.second.second;

        if(!IsParentSame(n1,n2)) {
            Union(n1,n2);
            mstWeight += dist;
            connected++;
        }
        // mst ??
        if(connected == N-1) {
            return mstWeight;
        }
    }
    // mst ???
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long totalWeight = 0;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a,b; long long c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
        totalWeight += c;
    }

    for(int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end());

    long long res = Kruskal();
    if(res == -1) {
        cout << -1;
    } else {
        cout << totalWeight - res;
    }


}