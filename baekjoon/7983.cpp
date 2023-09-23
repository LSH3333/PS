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

    int day = v.front().second;
    for(auto x : v) {
        int d = x.first, t = x.second;
        day = min(day, t);
        day = day - d;
    }

    cout << day;
}