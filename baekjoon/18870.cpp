#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>> v(N);
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        v[i] = {n, i};
    }
    sort(v.begin(), v.end());

    int num = 0;
    vector<pair<int,int>> ans(N);
    // 순서, 압축값
    ans[0] = {v[0].second, num};
    for(int i = 1; i < N; i++) {
        if(v[i].first != v[i-1].first) {
            ans[i] = {v[i].second, ++num};
        }
        else {
            ans[i] = {v[i].second, num};
        }
    }

    sort(ans.begin(), ans.end());
    for(auto x : ans) {
        cout << x.second << ' ';
    }
}