#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), cmp);

    int startTime = v.front().second;
    for(auto x : v) {
        int t = x.first, s = x.second;

        if(startTime <= s) {
            startTime = startTime - t;
        }
        else {
            startTime = s - t;
        }
    }

    if(startTime < 0) cout << -1;
    else cout << startTime;
}