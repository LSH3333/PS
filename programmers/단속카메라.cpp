#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 0;
    queue<pair<int,int>> q;
    sort(routes.begin(), routes.end());
    for(auto x : routes)
    {
        q.push({x[0], x[1]});
    }

    while(!q.empty())
    {
        int end = q.front().second;
        q.pop(); answer++;

        while(!q.empty() && q.front().first <= end)
        {
            end = min(end, q.front().second);
            q.pop();
        }
    }

    return answer;
}
