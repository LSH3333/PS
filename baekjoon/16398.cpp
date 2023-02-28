#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
// { {v1, v2}, cost }
vector<pair<pair<int,int>,long long>> v;
int parent[1010];

bool cmp(const pair<pair<int,int>,long long> &a, const pair<pair<int,int>,long long> &b) {
    return a.second < b.second;
}

int GetParent(int node) {
    if (node == parent[node]) return node;
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
    parent[max(node1,node2)] = min(node1, node2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
        for(int j = 1; j <= N; j++) {
            long long cost; cin >> cost;
            if(j > i) {
                v.push_back({{i, j}, cost});
            }
        }
    }

    sort(v.begin(), v.end(), cmp);

    int connected = 0;
    long long totalCost = 0;
    for(auto x : v) {
        int node1 = x.first.first, node2 = x.first.second;
        long long cost = x.second;

        if(!IsParentSame(node1, node2)) {
            Union(node1, node2);
            totalCost += cost;
            connected++;
        }

        if(connected == N-1) {
            break;
        }
    }

    cout << totalCost;
}