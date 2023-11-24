#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
#define MAX 500000

int N, W;
int leaf = 0;
vector<int> edges[MAX+1];
bool visited[MAX + 1];

void dfs(int n) {

    int cnt = 0;
    for(auto x : edges[n]) {
        if(visited[x]) continue;
        cnt++;
        visited[x] = true;
        dfs(x);
    }
    // ??
    if(cnt == 0) {
        leaf++;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> W;
    for(int i = 0; i < N-1; i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    visited[1] = true;
    dfs(1);

    double answer = (double)W / leaf;
    cout << fixed << setprecision(10) << answer;

}