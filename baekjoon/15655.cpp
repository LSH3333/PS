#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[10];

void dfs(vector<int> &res, int idx) {
    if(res.size() == M) {
        for(auto x : res) {
            cout << x << ' ';
        } cout << '\n';
        return;
    }

    for(int i = idx; i < N; i++) {
        res.push_back(arr[i]);
        dfs(res, i+1);
        res.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    vector<int> res;
    dfs(res, 0);
}