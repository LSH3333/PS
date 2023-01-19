#include <iostream>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    int N, n; cin >> N;
    while(N--) {
        cin >> n;
        if(n == 0) {
           if(pq.empty()) {
               cout << 0 << '\n';
           }
           else {
               cout << pq.top().second << '\n';
               pq.pop();
           }
        }
        else {
            pq.push({abs(n), n});
        }
    }
}