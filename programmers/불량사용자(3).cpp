#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool mark[10];
vector<string> v;
unordered_set<string> set;

bool Cal(string user, string banned)
{
    if(user.size() != banned.size()) return false;
    for(int i = 0; i < banned.size(); i++)
    {
        if(banned[i] == '*') user[i] = '*';
    }

    if(user != banned) return false;
    else return true;
}

void dfs(int idx, const vector<string> &user_id, const vector<string> &banned_id)
{
    if(idx == banned_id.size())
    {
        vector<string> tmp = v;
        sort(tmp.begin(), tmp.end());

        string str;
        for(auto x : tmp) str += x;
        set.insert(str);

        return;
    }

    for(int i = 0; i < user_id.size(); i++)
    {
        if(mark[i]) continue;
        if(!Cal(user_id[i], banned_id[idx])) continue;
        mark[i] = true;
        v.push_back(user_id[i]);
        dfs(idx+1, user_id, banned_id);
        mark[i] = false;
        v.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    dfs(0, user_id, banned_id);

//    for(auto x : set) cout << x << endl;
//    cout << set.size();

    return set.size();
}

int main()
{
    vector<string> user_id =
            {
                    "frodo", "fradi", "crodo", "abc123", "frodoc"
            };
    vector<string> banned_id =
            {
                    "fr*d*", "*rodo", "******", "******"
            };
    solution(user_id, banned_id);
}