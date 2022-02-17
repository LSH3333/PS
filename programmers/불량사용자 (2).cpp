#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<string> userID, bannedID;
bool mark[10];
vector<string> list;
unordered_set<string> set;

bool IsItBannedID(string id, int idx)
{
    string bi = bannedID[idx];
    if(bi.size() != id.size()) return false;

    vector<int> star;
    for(int i = 0; i < bi.size(); i++) if(bi[i] == '*') star.push_back(i);
    for(auto x : star) id[x] = '*';

    if(id != bi) return false;
    return true;
}

void dfs(int idx)
{
    if(idx == bannedID.size())
    {
//        for(auto x : list) cout << x << ' '; cout << endl;
        vector<string> _list = list;
        sort(_list.begin(), _list.end());
        string str;
        for(auto x : _list) str += x;
        set.insert(str);
        return;
    }

    for(int i = 0; i < userID.size(); i++)
    {
        if(mark[i]) continue;
        if(!IsItBannedID(userID[i], idx)) continue;
        list.push_back(userID[i]);
        mark[i] = true;
        dfs(idx+1);
        list.pop_back();
        mark[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    userID = user_id;
    bannedID = banned_id;

    dfs(0);

    int answer = set.size();
    return answer;
}
