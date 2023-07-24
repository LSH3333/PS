#include <iostream>
#include <queue>
using namespace std;

int N, M;
long long answer;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    priority_queue<long long, vector<long long>, greater<>> pq;
    for(int i = 0; i < N; i++) {
        long long n; cin >> n;
        pq.push(n);
    }

    while(M--) {
        long long n1, n2;
        n1 = pq.top();
        pq.pop();
        n2 = pq.top();
        pq.pop();

        pq.push(n1+n2);
        pq.push(n1+n2);
    }

    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    cout << answer;
}