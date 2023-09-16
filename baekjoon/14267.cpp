#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> child[100001];
int d[100001];
int a[100001];

void dfs(int n, int w) {
    w += a[n];
    d[n] += w;
    for (auto next: child[n]) {
        dfs(next, w);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        int parent; cin >> parent;
        if(parent == -1) continue;
        child[parent].push_back(i);
    }

    for(int i = 0; i < M; i++) {
        int n, w; cin >> n >> w;
        a[n] += w;
    }

    dfs(1, 0);

    for(int i = 1; i <= N; i++) {
        cout << d[i] << ' ';
    }

}