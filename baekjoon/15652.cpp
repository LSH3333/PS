#include <iostream>
#include <vector>
using namespace std;

int N, M;

void dfs(int idx, int depth, vector<int> &res) {
    if(depth == M) {
        for(auto x : res) cout << x << ' ';
        cout << '\n';
        return;
    }

    for(int i = idx; i <= N; i++) {
        res.push_back(i);
        dfs(i, depth+1, res);
        res.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    vector<int> res;
    dfs(1,0,res);
}