#include <iostream>
#include <queue>
using namespace std;

int N, M;

int main() {
    priority_queue<int> pq;

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        pq.push(n);
    }

    for(int i = 0; i < M; i++) {
        int n; cin >> n;
        int top = pq.top();

        if(pq.empty() || top - n < 0) {
            cout << 0;
            return 0;
        }

        pq.pop();
        if(top-n != 0) {
            pq.push(top-n);
        }
    }

    cout << 1;
}