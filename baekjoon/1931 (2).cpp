#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<pair<int,int>> v;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), cmp);

    int prevEndTime = v.front().second;
    answer = 1;

    for(int i = 1; i < N; i++) {
        int beginTime = v[i].first, endTime = v[i].second;
        if(beginTime >= prevEndTime) {
            answer++;
            prevEndTime = endTime;
        }
    }

    cout << answer;
}