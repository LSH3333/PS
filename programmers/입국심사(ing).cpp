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

    vector<pair<long long, int>> v;
    for(int i = 0; i < times.size(); i++)
        v.push_back({0, times[i]});

    int cnt = 0;
    while(true)
    {
        auto it_begin = v.begin() + cnt;
        long long val = it_begin->first + it_begin->second;

        auto it = upper_bound(it_begin, v.end(), make_pair(val, 0), cmp);
        int idx = it - v.begin();
        v.insert(v.begin() + idx, {val, it_begin->second});

//        cout << it_begin->first << ' ' << it_begin->second << endl;
        if(cnt == n)
        {
            answer = it_begin->first + it_begin->second;
            break;
        }
        cnt++;
    }

//    cout << answer;
    return answer;
}

int main()
{
    int n = 6;
    vector<int> times = {7, 10};
    solution(n, times);

}