#include <iostream>
#include <queue>
using namespace std;

int N, n;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int> pq;
    cin >> N;
    while(N--) {
        cin >> n;
        if(n == 0) {
            if(pq.empty()) cout << 0 << '\n';
            else { cout << pq.top() << '\n'; pq.pop(); }
        }
        else {
            pq.push(n);
        }
    }
}