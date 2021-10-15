#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    map<string, int> m;
    // 한글자 매핑
    for(int i = 0; i < 26; i++)
    {
        char c = (char)('A' + i);
        string str = "";
        str = c;
        m[str] = i+1;
    }

    int cnt = 27;
    for(int i = 0; i < msg.size(); i++)
    {
        // 2. 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다
        string str = "";
        bool trigger = false;
        for(int j = i; j < msg.size(); j++)
        {
            str += msg[j];
            if(m[str] == 0) { trigger = true; break; }
        }
        if(trigger)
        {
            // 4. w+c 사전에 등록
            m[str] = cnt++;
            str.pop_back();
        }
        // 3. w 출력
        answer.push_back(m[str]);
        i += str.size()-1;
    }

    //for(auto x : answer) cout << x << ' ';
    return answer;
}
