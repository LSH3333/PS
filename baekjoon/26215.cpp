#include <iostream>
#include <queue>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int> pq;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        pq.push(n);
    }

    int time = 0;
    while (time <= 1440 && !pq.empty()) {
        if(pq.size() == 1) {
            int house = pq.top();
            pq.pop();
            if(house - 1 > 0) {
                pq.push(house - 1);
            }
        }
        else {
            int house1 = pq.top();
            pq.pop();
            int house2 = pq.top();
            pq.pop();

            if(house1 - 1 > 0) {
                pq.push(house1-1);
            }
            if(house2 - 1 > 0) {
                pq.push(house2-1);
            }
        }
        time++;
    }

    if(time > 1440) {
        cout << -1;
    } else {
        cout << time;
    }
}