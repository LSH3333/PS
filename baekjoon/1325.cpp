#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> edges[10001];
bool mark[10001];
int maxVal;
int answer[10001];

int dfs(int node) {
    mark[node] = true;
    int cnt = 1;
    for (auto next: edges[node]) {
        if(mark[next]) continue;
        cnt += dfs(next);
    }

    return cnt;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        edges[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        memset(mark, false, sizeof(mark));
        answer[i] = dfs(i);
        maxVal = max(maxVal, answer[i]);
    }

    for(int i = 1; i <= N; i++) {
        if(answer[i] == maxVal) cout << i << ' ';
    }

}