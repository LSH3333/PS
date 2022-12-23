#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // first 기준 min heap
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<>> pq;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int t; cin >> t;
        pq.push({t, t});
    }

    for(int i = 0; i < M-1; i++) {
        long long time = pq.top().second;
        long long next = pq.top().first;
        pq.pop();
        pq.push({next + time, time});
    }

    cout << pq.top().first;
}