#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

struct cmp
{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.first > b.first;
    }
};

int solution(vector<int> food_times, long long k)
{
    deque<pair<int,int>> pq;

    long long sum = 0;
    for(int i = 0; i < food_times.size(); i++)
    {
        sum += food_times[i];
        pq.push_back({food_times[i], i+1});
    }
    if(sum <= k) return -1;
    sort(pq.begin(), pq.end(), less<>());

    long long rap = 0; // 몇바퀴
    while(true)
    {
        long long topTime = pq.front().first;
        topTime -= rap;

        if(k - (long long)pq.size() * topTime <= 0) break;
        else
        {
            k -= (long long)pq.size() * topTime;
            rap += topTime;
            pq.pop_front();
        }
    }

    vector<int> v;
    while(!pq.empty())
    {
        v.push_back(pq.front().second);
        pq.pop_front();
    }
    sort(v.begin(), v.end());

    return v[k % v.size()];
}

int main()
{
    vector<int> food_times = { 3, 1, 2 };
    solution(food_times, 5);
}