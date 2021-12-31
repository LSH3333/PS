#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

vector<string> userId, bannedId;
vector<int> v;
vector<vector<string>> ans;
set<string> s;
bool mark[10];

bool IsItBannedID(string banned, string id)
{
    if(banned.size() != id.size()) return false;
    for(int i = 0; i < banned.size(); i++)
    {
        if(banned[i] == '*')
        {
            id[i] = '*';
        }
    }

    if(banned != id) return false;

    return true;
}

void dfs(int idx)
{
    if(idx == bannedId.size())
    {
        string str = "";
        for(int i = 0; i < userId.size(); i++)
        {
            if(mark[i]) str += (i+'0');
        }
        s.insert(str);
        return;
    }
    string target = bannedId[idx];

    for(int i = 0; i < userId.size(); i++)
    {
        if(mark[i]) continue;
        if(IsItBannedID(target, userId[i]))
        {
            mark[i] = true;
            dfs(idx+1);
            mark[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    userId = user_id;
    bannedId = banned_id;

    dfs(0);

    answer = s.size();
    return answer;
}
