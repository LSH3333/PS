#include <iostream>
#include <queue>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    priority_queue<int, vector<int>, greater<>> pq;
    cin >> N;
    while(N--) {
        int n; cin >> n;
        pq.push(n);
    }

    int answer = 0;
    while (!pq.empty()) {
        int n1 = pq.top();
        pq.pop();
        if(pq.empty()) break;
        int n2 = pq.top();
        pq.pop();
        pq.push(n1+n2);
        answer += (n1 + n2);
    }
    cout << answer;
}