#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// priority queue, min heap
struct cmp
{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.first > b.first;
    }
};

int solution(vector<int> food_times, long long k)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    long long sum = 0;
    for(int i = 0; i < food_times.size(); i++)
    {
        sum += food_times[i];
        pq.push({food_times[i], i+1});
    }
    if(sum <= k) return -1;

    long long last = 0;
    while(true)
    {
        long long sub = k - ((pq.top().first - last) * pq.size());
        if(sub > 0)
        {
            k = sub;
            last = pq.top().first;
            pq.pop();
        }
        else
        {
            break;
        }
    }

    vector<int> v;
    while(!pq.empty())
    {
        v.push_back(pq.top().second);
        pq.pop();
    }
    sort(v.begin(), v.end());
    int answer =  v[k % v.size()];
    return answer;
}

int main()
{
    vector<int> food_times = {3,1,2};
    solution(food_times, 5);
}