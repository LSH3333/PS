#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;


vector<string> solution(vector<string> record)
{
    // Enter or Leave, UID
    vector<pair<string, string>> enter;
    unordered_map<string, string> nickname;

    for(auto x : record)
    {
        string token;
        vector<string> v;
        stringstream ss(x);
        while(ss >> token) v.push_back(token);

        if(v[0] == "Enter")
        {
            enter.push_back({v[0], v[1]});
            nickname[v[1]] = v[2];
        }
        else if(v[0] == "Leave")
        {
            enter.push_back({v[0], v[1]});
        }
        else
        {
            nickname[v[1]] = v[2];
        }
    }

    vector<string> answer;
    for(auto x : enter)
    {
        string str;
        if(x.first == "Enter")
        {
            str = nickname[x.second] + "님이 들어왔습니다.";
        }
        else
        {
            str = nickname[x.second] + "님이 나갔습니다.";
        }
        answer.push_back(str);
    }

//    for(auto x : answer) cout << x << endl;
    return answer;
}

int main()
{
    vector<string> record =
            {
                    "Enter uid1234 Muzi",
                    "Enter uid4567 Prodo",
                    "Leave uid1234",
                    "Enter uid1234 Prodo",
                    "Change uid4567 Ryan"
            };
    solution(record);
}