#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>
using namespace std;

map<char,char> m;

bool IsCorrect(string s)
{
    stack<char> st;

    for(int i = 0; i < s.size(); i++)
    {
        if(st.empty())
        {
            st.push(s[i]);
            continue;
        }

        if(m[st.top()] == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    return st.empty();
}

int solution(string s) {
    int answer = 0;

    m['['] = ']';
    m['('] = ')';
    m['{'] = '}';

    for(int i = 0; i < s.size(); i++)
    {
        string temp = s.substr(1, s.size()-1) + s[0];
        s = temp;
        if(IsCorrect(s)) answer++;
    }

    return answer;
}
