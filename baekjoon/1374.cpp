#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

struct qCmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
        if(a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    priority_queue<pair<int,int>, vector<pair<int,int>>, qCmp> pq;
    vector<pair<int,int>> v(N);
    for(int i = 0; i < N; i++) {
        int n;
        cin >> n >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    int answer = 0;
    for(auto x : v) {
        if (pq.empty()) {
            pq.push(x);
        }
        else {
            while (!pq.empty() && pq.top().second <= x.first) {
                pq.pop();
            }
            pq.push(x);
        }
        answer = max(answer, (int)pq.size());
    }

    cout << answer;
}