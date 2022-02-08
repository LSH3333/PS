#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());

    while(n > 0)
    {
        int top = pq.top();
        if(top == 0) break;
        pq.pop();
        top--; n--;
        pq.push(top);
    }

    while(!pq.empty())
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}