#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool visited[10010];

void dfs(int depth, vector<int> &org, vector<int> &res) {
    if(depth == M) {
        for(auto x : res) {
            cout << x << ' ';
        } cout << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        res.push_back(org[i]);
        dfs(depth+1, org, res);
        res.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<int> res;
    dfs(0, v, res);

}