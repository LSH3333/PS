#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

map<string, string> m;
vector<pair<string,int>> l;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    for(int i = 0; i < record.size(); i++)
    {
        stringstream ss;
        ss. str(record[i]);

        vector<string> v;
        string token;
        while(ss >> token)
        {
            v.push_back(token);
        }

        if(v[0] == "Enter" || v[0] == "Change")
        {
            m[v[1]] = v[2];
        }

        if(v[0] == "Enter")
            l.push_back({v[1], 0});
        else if(v[0] == "Leave")
            l.push_back({v[1], 1});
    }

    for(auto x : l)
    {
        string s;
        // Enter
        if(x.second == 0)
        {
            s = m[x.first] + "님이 들어왔습니다.";
        }
        else
        {
            s = m[x.first] + "님이 나갔습니다.";
        }
        answer.push_back(s);
    }

    return answer;
}

int main()
{
    vector<string> record = {
            "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"
    };
    solution(record);
}