#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int maxN;
map<string, vector<pair<string,bool>>> m;
map<string, int> mcnt;
vector<string> answer;

void dfs(string loc)
{
    // graph 끝에 도달했는데 모든 공항 방문하지 않았다면
    if(mcnt[loc] == 0 && answer.size() < maxN)
    {
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
        mcnt[i[0]]++;
    }

    for(auto &x : m) sort(x.second.begin(), x.second.end());

    for(auto x : m)
    {
        cout << x.first << ": ";
        for(auto y : x.second)
        {
            cout << y.first << ' ';
        }cout << endl;
    }


    answer.push_back("ICN");
    dfs("ICN");
    for(auto x : answer) cout << x << ' ';
    return answer;

}

int main()
{
    vector<vector<string>> tickets =
            {
                    {"ICN", "SFO"},
                    {"ICN", "ATL"},
                    {"SFO", "ATL"},
                    {"ATL", "ICN"},
                    {"ATL", "SFO"}
            };

    vector<vector<string>> tickets2 =
            {
                    {"A", "B"},
                    {"A", "C"},
                    {"C", "A"}
            };

    vector<vector<string>> tickets3 =
            {
                    {"ICN", "A"},
                    {"A", "B"},
                    {"A", "C"},
                    {"B", "D"},
                    {"C", "A"},
            };

    solution(tickets3);
}