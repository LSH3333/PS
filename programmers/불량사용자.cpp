#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> userId, bannedId;
vector<string> v;
vector<vector<string>> ans;
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
    string target = bannedId[idx];
    if(idx == bannedId.size())
    {
        ans.push_back(v);
        return;
    }

    for(int i = 0; i < userId.size(); i++)
    {
        if(mark[i]) continue;
        if(IsItBannedID(target, userId[i]))
        {
            mark[i] = true;
            v.push_back(userId[i]);

            dfs(idx+1);

            mark[i] = false;
            v.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    for(auto x : user_id) userId.push_back(x);
    for(auto x : banned_id) bannedId.push_back(x);
    dfs(0);

    for(auto &x : ans)
    {
        sort(x.begin(), x.end());
    }
//    for(auto x : ans)
//    {
//        for(auto y : x)
//        {
//            cout << y << ' ';
//        } cout << endl;
//    } cout << endl;

    vector<string> sortedAns;
    for(int i = 0; i < ans.size(); i++)
    {
        string tmp = "";
        for(int j = 0; j < ans[i].size(); j++)
        {
            tmp += ans[i][j];
        }
        sortedAns.push_back(tmp);
    }

//    for(auto x : sortedAns) cout << x << endl; cout << endl;
    sort(sortedAns.begin(), sortedAns.end());
    sortedAns.erase(unique(sortedAns.begin(), sortedAns.end()), sortedAns.end());
//    for(auto x : sortedAns) cout << x << endl;


    answer = sortedAns.size();
//    cout << answer;
    return answer;
}

int main()
{
    vector<string> user_id =
            {
                    "frodo", "fradi", "crodo", "abc123", "frodoc"
            };
    vector<string> banned_id =
            {
                    "*rodo", "*rodo", "******"
            };

    vector<string> user_id1 =
            {
                    "frodo", "fradi", "crodo", "abc123", "frodoc"
            };
    vector<string> banned_id1 =
            {
                    "fr*d*", "abc1**"
            };

    vector<string> user_id3 =
            {
                    "frodo", "fradi", "crodo", "abc123", "frodoc"
            };
    vector<string> banned_id3 =
            {
                    "fr*d*", "*rodo", "******", "******"
            };
    solution(user_id1, banned_id1);
}