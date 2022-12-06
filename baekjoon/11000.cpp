#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;

// second 기준 min heap
struct cmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    vector<pair<int,int>> v(N);
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    for(int i = 0; i < N; i++) {
        int a,b; cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end());

    int answer = 1;
    int idx = 0;
    while(idx < N) {
        if(pq.empty()) {
            pq.push(v[idx]);
        }
        else {
            // 새로운 강의실 필요
            if(v[idx].first < pq.top().second) {
                answer++;
                pq.push(v[idx]);
            }
            else {
                pq.pop();
                pq.push(v[idx]);
            }
        }

        idx++;
    }

    cout << answer;
}