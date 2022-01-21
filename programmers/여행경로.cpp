#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int maxN;
map<string, vector<pair<string,bool>>> m;
vector<string> answer, ans;
bool trigger;

void dfs(string loc)
{
    if(trigger) return;
    // 모든 경로 찾음
    if(answer.size() == maxN+1 && !trigger)
    {
        trigger = true;
        for(auto x : answer) ans.push_back(x);
        return;
    }


    for(auto &x : m[loc])
    {
        if(x.second) continue;

        x.second = true;
        answer.push_back(x.first);

        dfs(x.first);

        x.second = false;
        answer.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    maxN = tickets.size();

    for(auto i : tickets)
    {
        m[i[0]].push_back({i[1], false});
    }

    for(auto &x : m) sort(x.second.begin(), x.second.end());

    answer.push_back("ICN");
    dfs("ICN");
    return ans;
}
