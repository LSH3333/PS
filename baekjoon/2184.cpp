#include <iostream>
#include <queue>
using namespace std;

int N, P, answer;
priority_queue<int> pq[7]; // max heap

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> P;
    for(int i = 0; i < N; i++) {
        int string, fret; cin >> string >> fret;

        while(!pq[string].empty() && pq[string].top() > fret) {
            pq[string].pop();
            answer++;
        }
        if(!pq[string].empty() && pq[string].top() == fret) continue;

        pq[string].push(fret);
        answer++;
    }

    cout << answer;
}