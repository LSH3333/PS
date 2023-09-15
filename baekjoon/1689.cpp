#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer;

struct cmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>> v(N);
    // second ?? min-heap pq
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp > pq;
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    // first ?? ???? ??
    sort(v.begin(), v.end());

    for(auto x : v) {
        int s = x.first, e = x.second;
        if(pq.empty()) {
            pq.push({s, e});
        }
        else {
            while(!pq.empty() && s >= pq.top().second) {
                pq.pop();
            }
            pq.push({s, e});
        }

        answer = max(answer, (int)pq.size());
    }

    cout << answer;
}