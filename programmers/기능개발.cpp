#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q;
    for(int i = 0; i < progresses.size(); i++)
    {
        int leftWork = 100 - progresses[i];
        int leftDays = leftWork / speeds[i];
        if((leftWork % speeds[i]) != 0) leftDays++;

        if(q.empty()) { q.push(leftDays); continue; }

        if(leftDays > q.front())
        {
            answer.push_back(q.size());
            q = queue<int>(); // 큐초기화
            q.push(leftDays);
        }
        else
        {
            q.push(leftDays);
        }
    }
    answer.push_back(q.size());

    return answer;
}