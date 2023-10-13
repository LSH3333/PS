#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, H, T;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int> pq; // max heap
    cin >> N >> H >> T;
    for(int i = 0; i < N; i++) {
        int h; cin >> h;
        pq.push(h);
    }

    int t = 0;
    while(!pq.empty() && t < T && pq.top() >= H) {
        int top = pq.top();
        pq.pop();
        int half = floor(top/2);
        if(half != 0) {
            pq.push(half);
        }
        t++;
    }

    if(pq.top() < H) {
        cout << "YES\n";
        cout << t;
    } else {
        cout << "NO\n";
        cout << pq.top();
    }

}