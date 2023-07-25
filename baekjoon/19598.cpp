#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer;


struct qCmp {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
        if(a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>> v(N);
    // second ?? min heap
    priority_queue<pair<int,int>, vector<pair<int,int>>, qCmp> pq;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
    }


    sort(v.begin(), v.end());

    for(auto x : v) {
        if(pq.empty()) {
            pq.push(x);
        }
        else {
            if(pq.top().second <= x.first) {
                pq.pop();
                pq.push(x);
            }
            else {
                pq.push(x);
            }
        }

        answer = max(answer, (int)pq.size());
    }

    cout << answer;
}