#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool cmp(const pair<double,int> &a, const pair<double,int> &b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages)
{
    sort(stages.begin(), stages.end());
    deque<int> st(stages.begin(), stages.end());

    vector<pair<double, int>> v;
    for(int i = 1; i <= N; i++)
    {
        if(st.front() != i)
        {
            v.push_back({0, i});
            continue;
        }
        int size = (int)st.size();
        int cnt = 0;
        while(!st.empty() && st.front() == i) { st.pop_front(); cnt++; }
        v.push_back({ (double)cnt / size, i});
    }

    vector<int> answer;
    sort(v.begin(), v.end(), cmp);
//    for(auto x : v) cout << x.second << ' ';
    for(auto x : v) answer.push_back(x.second);
    return answer;
}

int main()
{
    vector<int> stages = {2,1,2,6,2,4,3,3};
//    vector<int> stages = {1,2};

//    solution(1, stages);
    for(int i = 1; i <= 100; i++)
    {
        cout << (double)0 / i;
    }
}