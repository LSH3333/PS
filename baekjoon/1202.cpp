#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, K;
long long answer;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    priority_queue<int> pq; // max heap
    vector<pair<int,int>> jewels(N);
    vector<int> bags(K);

    for(int i = 0; i < N; i++) {
        int m, v; cin >> m >> v; // 무게, 가격
        jewels[i] = {m, v};
    }
    for(int i = 0; i < K; i++) {
        cin >> bags[i];
    }

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());


    int jewelIdx = 0;
    for(auto bag : bags) {
        while(jewelIdx < N && jewels[jewelIdx].first <= bag) {
            pq.push(jewels[jewelIdx].second);
            jewelIdx++;
        }

        if(!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;
}