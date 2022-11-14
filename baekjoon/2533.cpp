#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> edges[1000010];
int mark[1000010][2];
bool visited[1000010];

/**
 * status = 1 : 얼리 어뎁터
 * status = 0 : 얼리 어뎁터 x
 */
void dfs(int node) {
    // "얼리 어뎁터 노드"와 연결된 노드들은 얼리 어뎁터여도 되고 아니어도 됨
    // "얼리 어뎁터가 아닌 노드"와 연결된 노드들은 무조건 얼리 어뎁터여야만 함
    visited[node] = true;
    mark[node][1] = 1;
    for (auto next: edges[node]) {
        if(visited[next]) continue;
        dfs(next);
        mark[node][0] += mark[next][1];
        mark[node][1] += min(mark[next][0], mark[next][1]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1);
//    cout << mark[1][0] << ' ' << mark[1][1] << endl;
    cout << min(mark[1][0], mark[1][1]);
}