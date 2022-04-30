#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg)
{
    unordered_map<string, int> dic;

    for(int i = 0; i < 26; i++)
    {
        char c = (char)('A'+i);
        string s; s.push_back(c);
        dic[s] = i+1;
    }

    vector<int> answer;
    int cnt = 27;
    for(int i = 0; i < msg.size();)
    {
        string s;
        int j;
        for(j = i; j < msg.size(); j++)
        {
            s.push_back(msg[j]);
            if(dic[s] == 0) break;
        }

        if(j >= msg.size())
        {
            answer.push_back(dic[s]);
            break;
        }

        dic[s] = cnt++; // 사전에 추가
        s.pop_back();
        answer.push_back(dic[s]); // 출력

        i = j;
    }

    return answer;
}

int main()
{
    string msg = "ABABABABABABABAB";
    solution(msg);
}