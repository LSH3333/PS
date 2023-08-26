#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool cmpSecond(const pair<int,int> &a, const pair<int,int> &b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>> v;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        v.push_back({i, n});
    }

    sort(v.begin(), v.end(), cmpSecond);


    for(int i = 0; i < N; i++) {
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    for(auto x : v) {
        cout << x.second << ' ';
    }
}