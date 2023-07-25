#include <queue>
#include <iostream>
using namespace std;

int N, answer;

int main() {
    // min heap
    priority_queue<int, vector<int>, greater<>> pq;

    cin >> N;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        pq.push(n);
    }

    while ((int)pq.size() > 1) {
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();

        answer += n1 + n2;
        pq.push(n1 + n2);
    }

    cout << answer;
}