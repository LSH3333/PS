#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;

// pq second (점수) 기준 min heap
struct cmp {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>> v(N);
    for(int i = 0; i < N; i++) {
        int d, w; cin >> d >> w;
        v[i] = {d, w};
    }

    // d 기준 오름 차순
    sort(v.begin(), v.end());
    // 점수 기준 min heap
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;


    for(auto x : v) {
        int d = x.first, w = x.second;

        if(d > pq.size()) {
            pq.push({d, w});
        }
        else {
            if(pq.top().second < w) {
                pq.pop();
                pq.push({d, w});
            }
        }
    }

    int answer = 0;
    while(!pq.empty()) {
        answer += pq.top().second;
        pq.pop();
    }

    cout << answer;
}