#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000

int N, M, K;
int parent[MAX+1];
bool powerPlant[MAX+1];

int GetParent(int node) {
    if(node == parent[node]) return node;
    return parent[node] = GetParent(parent[node]);
}

// Union 가능 여부
bool IsUnionPossible(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);

    // 부모가 같을 경우 : union 불가
    if(node1 == node2) return false;
    // 두 부모 모두 발전소일 경우 : union 불가
    if(powerPlant[node1] && powerPlant[node2]) return false;


    // 부모가 다른 경우 : union 가능
    // 두 부모 모두 발전소 아닐 경우
    if (!powerPlant[node1] && !powerPlant[node2]) {
        parent[max(node1,node2)] = min(node1,node2);
        return true;
    }
    // 한쪽이 발전소일 경우
    if(powerPlant[node1] + powerPlant[node2] == 1) {
        // 발전소를 부모로 한다
        if(powerPlant[node1]) {
            parent[node2] = node1;
        }
        else {
            parent[node1] = node2;
        }
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++) {
        int n; cin >> n;
        powerPlant[n] = true;
    }

    vector<pair<int,pair<int,int>>> v(M);
    for(int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[i] = {c, {a, b}};
    }
    sort(v.begin(), v.end());

    for(int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    int answer = 0, cnt = 0;
    for(auto x : v) {
        int node1 = x.second.first, node2 = x.second.second;
        int cost = x.first;

        if (IsUnionPossible(node1, node2)) {
            answer += cost;
            cnt++;
        }
        if(cnt == N-K) break;
    }

    cout << answer;
}