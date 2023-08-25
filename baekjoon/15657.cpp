#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool visited[10];

void dfs(int idx, int depth, const vector<int> &v, vector<int> &res) {
    if(depth == M) {
        for(const auto &x : res) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = idx; i < N; i++) {
        res.push_back(v[i]);
        dfs(i, depth+1, v, res);
        res.pop_back();
    }
}

int main() {
    cin >> N >> M;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());


    vector<int> res;
    dfs(0, 0, v, res);
}