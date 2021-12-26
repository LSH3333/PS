#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct cmp
{
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[1] > b[1];
    }
};


int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>,vector<vector<int>>, cmp> pq;

//    while(!pq.empty())
//    {
//        cout << pq.top()[0] << ' ' << pq.top()[1] << endl;
//        pq.pop();
//    }

    int time = 0;
    int idx = 0;
    while(idx < jobs.size() || !pq.empty())
    {
        if(idx < jobs.size() && jobs[idx][0] <= time)
        {
            pq.push(jobs[idx++]);
            continue;
        }

        if(pq.empty()) time = jobs[idx][0];
        else
        {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
    }

//    cout << answer/jobs.size() << endl;
    answer = answer / jobs.size();
    return answer;
}
