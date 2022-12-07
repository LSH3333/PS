#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;

// second 기준 min heap
struct cmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    vector<pair<int,int>> v(N);
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
    }
    // first 기준 오름 차순 정렬
    sort(v.begin(), v.end());

    int time = 1; // 데드라인이 time 이상인 숙제들 처리 가능
    for(auto x : v) {
        // 데드 라인이 time 이상, pq에 삽입
        if(x.first >= time) {
            pq.push(x);
            time++;
        }
        // 데드 라인이 time 미만 이기 때문에, 이미 pq에 넣은 일들 중 가장 컵라면 적은 일을 빼고 넣음
        else {
            pq.pop();
            pq.push(x);
        }
    }

    int answer = 0;
    while(!pq.empty()) {
        answer += pq.top().second;
        pq.pop();
    }
    cout << answer;
}