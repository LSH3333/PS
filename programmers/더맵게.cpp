#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    // min heap
    priority_queue<int, vector<int> ,greater<int>> pq(scoville.begin(), scoville.end());

    // 스코빌 지수 가장 작은것이 pq의 top에 오게됨
    while(pq.top() < K)
    {
        if(pq.size() == 1) return -1;

        int smallest1 = pq.top(); pq.pop();
        int smallest2 = pq.top(); pq.pop();
        int newScoville = smallest1 + smallest2 * 2;

        pq.push(newScoville);
        answer++;
    }

    return answer;
}
