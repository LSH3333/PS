#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string,string> m =
        {
                {"zero", "0"}, {"one","1"}, {"two","2"}, {"three","3"},
                {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"},
                {"eight", "8"}, {"nine", "9"}
        };

int solution(string s) {
    int answer = 0;

    string ans = "";
    string temp = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            temp += s[i];
        }
        else
        {
            ans += s[i];
        }

        // 숫자완성 여부 확인
        if(temp.size() >= 3)
        {
            if(m.find(temp) == m.end()) continue;
            else { ans += m[temp]; temp = ""; }
        }
    }

    answer = stoi(ans);
    cout << answer;
    return answer;
}

int main()
{
    string s = "2three45sixseven";
    solution(s);
}