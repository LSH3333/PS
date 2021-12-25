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

//
//    for(auto x : jobs)
//    {
//        cout << x[0] << ' ' << x[1] << endl;
//    }

    int time = 0;
    int idx = 0;
    while(idx < jobs.size())
    {
        priority_queue<vector<int>,vector<vector<int>>, cmp> pq;
        for(int i = idx; i < jobs.size(); i++)
        {
            if(jobs[i][0] > time) break;
            if(jobs[i][0] <= time) { pq.push(jobs[i]); }
        }
        idx++;

        if(pq.empty()) time = jobs[idx][0];
        else
        {
            cout << "idx: " << idx << endl;
            cout << pq.top()[0] << ' ' << pq.top()[1] << endl;
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
    }

    cout << answer/jobs.size() << endl;
    answer = answer / jobs.size();
    return answer;
}

int main()
{
    vector<vector<int>> jobs =
            {
                    {0,3}, {1,9}, {2,6}
            };

    vector<vector<int>> jobs2 =
            {
                    {0,3}, {0,4}, {1,9}, {2,6}, {7,1}
            };
    vector<vector<int>> jobs3 =
            {
                    {0,10}, {4,10}, {15,2}, {5,11}
            };
    solution(jobs3);
}