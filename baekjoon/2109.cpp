#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<int> v[10010];
    for(int i = 0; i < N; i++) {
        int money, day; cin >> money >> day;
        v[day].push_back(money);
    }

    for(int i = 1; i <= 10000; i++) {
        if(v[i].empty()) continue;
        // 내림차순 정렬
        sort(v[i].begin(), v[i].end(), greater<>());
    }

    priority_queue<int, vector<int>, greater<>> pq; // min heap

    for(int day = 1; day <= 10000; day++) {
        if(v[day].empty()) continue;

        for(auto money : v[day]) {
            if(pq.size() < day) {
                pq.push(money);
            }
            else if(money > pq.top()) {
                pq.pop();
                pq.push(money);
            }
        }
    }

    int answer = 0;
    while(!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    cout << answer;
}