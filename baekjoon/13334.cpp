#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, D, answer;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>> lines(N);
    // min heap
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 0; i < N; i++) {
        int h, o; cin >> h >> o;
        lines[i] = {min(h, o), max(h, o)};
    }
    cin >> D;
    // 끝 점 기준 오름차순 정렬
    sort(lines.begin(), lines.end(), cmp);


    for(auto line : lines) {
        int l = line.first, r = line.second;
        if(r - l > D) continue;

        if(pq.empty()) {
            pq.push(l);
        }
        else {
            int newL = r - D;
            // 새로운 시작점보다 왼쪽에 있는 시작점은 pop
            while (!pq.empty() && pq.top() < newL) {
                pq.pop();
            }
            pq.push(l);
        }

        answer = max(answer, (int)pq.size());
    }

    cout << answer;
}