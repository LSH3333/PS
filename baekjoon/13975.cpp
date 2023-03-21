#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;

    while(T--) {
        // min heap
        priority_queue<long long, vector<long long>, greater<>> pq;
        int N;
        cin >> N;
        for(int i = 0; i < N; i++) {
            long long n; cin >> n;
            pq.push(n);
        }

        long long answer = 0;
        while (pq.size() >= 2) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            answer += a + b;
            pq.push(a+b);
        }

        cout << answer << '\n';
    }

}