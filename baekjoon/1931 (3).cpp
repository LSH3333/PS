#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<pair<int,int>> v;
    int answer = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);

    int endTime = -1;
    for(auto x : v) {
        int s = x.first, e = x.second;

        if(s >= endTime) {
            answer++;
            endTime = e;
        }
    }

    cout << answer;
}