#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 0;
vector<int> e[20];
vector<int> v;
vector<int> cur;
bool mark[20];

void dfs()
{
    int sheep = 0, wolf = 0;
    for(auto x : cur)
    {
        if(v[x] == 0) sheep++;
        else wolf++;
    }
    if(sheep <= wolf) return;
    answer = max(answer, sheep);
    
    vector<int> next = cur;
    for(auto x : next)
    {
        for(auto y : e[x])
        {
            if(mark[y]) continue;
            cur.push_back(y);
            mark[y] = true;
            dfs();
            cur.pop_back();
            mark[y] = false;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) 
{
    v = info;
    for(auto x : edges) e[x[0]].push_back(x[1]);

    mark[0] = true;
    cur.push_back(0);
    dfs();
    return answer;
}