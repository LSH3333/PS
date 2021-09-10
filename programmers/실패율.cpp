#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 실패율 같다면, 작은 번호 스테이지 먼저 오도록
bool cmp(const pair<double,int> &a, const pair<double,int> &b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int max = stages.size();
    sort(stages.begin(), stages.end());

    vector<pair<double, int>> v;
    for(int st = 1; st <= N; st++)
    {
        int lower = lower_bound(stages.begin(), stages.end(), st) - stages.begin();
        int upper = upper_bound(stages.begin(), stages.end(), st) - stages.begin();
        // 스테이지에 도달했으나 아직 클리어하지 못한 사람 수
        int cnt = upper - lower;
        // 스테이지에 도달한 사람 수
        int trying = max - lower;

        // 스테이지에 도달한 유저가 없는 경우
        if(lower == upper)
        {
            v.push_back({0,st});
        }
        else
        {
            double failRate = (double)cnt / (double)trying;
            v.push_back({failRate, st});
        }
    }

    sort(v.begin(), v.end(), cmp);

    for(auto x : v)
        answer.push_back(x.second);

    return answer;
}

int main()
{
    int n = 5;
    vector<int> stages = {2,1,2,6,2,4,3,3};
    solution(n,stages);
}