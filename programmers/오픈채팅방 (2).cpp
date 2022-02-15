#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record)
{
    unordered_map<string, string> NickName;
    for(auto x : record)
    {
        stringstream ss(x);
        vector<string> tokens;
        string token;
        while(ss >> token) tokens.push_back(token);

        if(tokens[0] == "Leave") continue;
        NickName[tokens[1]] = tokens[2];
    }

    vector<string> answer;
    for(auto x : record)
    {
        stringstream ss(x);
        vector<string> tokens;
        string token;
        while(ss >> token) tokens.push_back(token);

        if(tokens[0] == "Change") continue;
        string alarm = NickName[tokens[1]];
        if(tokens[0] == "Enter")
        {
            alarm += "님이 들어왔습니다.";
        }
        else if(tokens[0] == "Leave")
        {
            alarm += "님이 나갔습니다.";
        }
        answer.push_back(alarm);
    }

    return answer;
}
