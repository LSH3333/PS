#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

void dfs(vector<int> &res) {
    if(res.size() == M) {
        for(auto x : res) {
            cout << x << ' ';
        } cout << '\n';
        return;
    }

    for(int i = 0; i < v.size(); i++) {
        res.push_back(v[i]);
        dfs(res);
        res.pop_back();
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<int> res;
    dfs(res);
}