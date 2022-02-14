#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    unordered_map<string, int> dic;
    for(int i = 1; i <= 26; i++)
    {
        char c = 'A' + i - 1;
        string s = ""; s.push_back(c);
        dic[s] = i;
    }

    int dicIdx = 27;
    int idx = 0;
    while(idx < msg.size())
    {
        string str = "";
        for(int i = idx; i < msg.size(); i++)
        {
            str.push_back(msg[i]);
            if(dic[str] == 0) break;
        }
        // 여기서 맨뒤 문자 pop 하기전에 이미 사전에 있는 문자라면 끝 도달한것
        if(dic[str] != 0)
        {
            answer.push_back(dic[str]);
            break;
        }

        // w+c 사전 기록
        dic[str] = dicIdx++;
        // 맨뒤 문자 pop
        str.pop_back();

        answer.push_back(dic[str]);
        idx += str.size();
    }

    return answer;
}