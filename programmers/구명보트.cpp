#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    deque<int> dq(people.size());

    sort(people.begin(), people.end(), greater<>());
    for(int i = 0; i < people.size(); i++) dq[i] = people[i];

    //for(auto x : dq) cout << x << ' '; cout << endl;

    while(dq.size() > 1)
    {
        //cout << answer << endl;
        if(dq.front() + dq.back() <= limit)
        {
            dq.pop_front();
            dq.pop_back();
        }
        else
        {
            dq.pop_front();
        }
        answer++;
    }
    if(!dq.empty()) answer++;
    return answer;
}