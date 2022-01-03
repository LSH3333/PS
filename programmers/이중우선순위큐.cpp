#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    // 내림차순 정렬 
    priority_queue<int, vector<int>, less<>> less_pq;
    // 오름차순 정렬 
    priority_queue<int, vector<int>, greater<>> greater_pq;
    int pqSize = 0;
    for(int i = 0; i < operations.size(); i++)
    {
        char op = operations[i][0];
        int num = stoi(operations[i].substr(2));

        if(op == 'I')
        {
            greater_pq.push(num);
            less_pq.push(num);
            pqSize++;
        }
        else
        {
            // pq 크기 0이면 무시 
            if(pqSize == 0) continue;
            if(num == 1)
            {
                less_pq.pop();
            }
            else
            {
                greater_pq.pop();
            }
            pqSize--;
        }
    }
    // pq 크기 0이면 [0,0] 리턴 
    if(pqSize == 0) { answer.push_back(0); answer.push_back(0); return answer; }

    answer.push_back(less_pq.top());
    int cnt = 0;
    while(!less_pq.empty())
    {
        if(cnt == pqSize-1)
        {
            answer.push_back(less_pq.top());
            break;
        }
        less_pq.pop();
        cnt++;
    }

    return answer;
}