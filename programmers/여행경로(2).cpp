#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, vector<pair<string,bool>>> m;
vector<string> answer;
int N;
bool foundAnswer;

void dfs(string node, int depth)
{
    if(foundAnswer) return;
    if(depth == N)
    {
        foundAnswer = true;
        return;
    }

    for(auto &x : m[node])
    {
        if(x.second) continue;
        answer.push_back(x.first);
        x.second = true;

        dfs(x.first, depth+1);
        if(foundAnswer) return; // 정답 이미 찾았을시 dfs 더이상 진행 하지 않음
        answer.pop_back();
        x.second = false;
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    N = tickets.size();
    for(auto x : tickets) m[x[0]].push_back({x[1], false});

    for(auto &x: m)
    {
        sort(x.second.begin(), x.second.end());
    }

    answer.push_back("ICN");
    dfs("ICN", 0);
    return answer;
}
