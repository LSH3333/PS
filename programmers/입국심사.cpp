#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.first < b.first;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());

    long long left = 0, right = (long long)times.back() * n;
    while(left <= right)
    {
        long long mid = (left + right) / 2;

        long long sum = 0;
        for(int i = 0; i < times.size(); i++)
            sum += mid / (long long)times[i];

        if(sum >= n)
        {
            right = mid - 1;
            answer = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
//    cout << answer;
    return answer;
}
