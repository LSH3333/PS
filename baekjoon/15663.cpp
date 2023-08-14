#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool visited[10];
vector<vector<int>> answer;

void dfs(int depth, vector<int> &res, vector<int> &org) {
    if(depth == M) {
        answer.push_back(res);
        return;
    }

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        res.push_back(org[i]);
        dfs(depth+1, res, org);
        visited[i] = false;
        res.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    vector<int> v(N);
    vector<int> res;
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

//    sort(v.begin(), v.end());

    dfs(0, res, v);

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    for(auto x : answer) {
        for(auto y : x) {
            cout << y << ' ';
        } cout << '\n';
    }
}