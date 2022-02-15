#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,double> &a, const pair<int,double> &b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<pair<int,double>> v;
    deque<int> dq(stages.begin(), stages.end());
    sort(dq.begin(), dq.end());

    for(int stage = 1; stage <= N; stage++)
    {
        if(dq.front() != stage)
        {
            v.push_back({stage, 0});
            continue;
        }

        int a = 0;
        int b = dq.size();
        while(dq.front() == stage)
        {
            dq.pop_front();
            a++;
        }
        double failure = (double)a / (double)b;
        v.push_back({stage, failure});
    }


    sort(v.begin(), v.end(), cmp);
    vector<int> answer;
    for(auto x : v) answer.push_back(x.first);

    return answer;
}
