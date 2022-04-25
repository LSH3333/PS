#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 올바른 괄호 문자열이라면 참 리턴
bool IsItRightStr(string s)
{
    stack<char> st;
    for(auto x : s)
    {
        if(st.empty()) { st.push(x); continue; }

        if(st.top() == '(' && x == ')') st.pop();
        else st.push(x);
    }
    if(st.empty()) return true;
    else return false;
}

string Sol(string s)
{
    // 1
    if(s.empty()) return s;

    // 2
    string u, v;
    int open = 0, close = 0;
    int i;
    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == '(') open++;
        else close++;
        u.push_back(s[i]);
        if(open == close) break;
    }
    v = s.substr(i+1);

    // 3
    if(IsItRightStr(u))
    {
        return u + Sol(v);
    }
    // 4
    else
    {
        string ret = "(";
        ret += Sol(v);
        ret += ')';
        u = u.substr(1);
        u.pop_back();
        for(int i = 0; i < u.size(); i++)
        {
            if(u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        ret += u;
        return ret;
    }
}

string solution(string s)
{
    string answer = Sol(s);
    return answer;
}

int main()
{
    string s = ")(";
    solution(s);
}