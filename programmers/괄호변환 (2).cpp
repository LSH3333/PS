#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool IsItCorrect(string s)
{
    while(!s.empty())
    {
        bool erased = false;
        for(int i = 0; i < s.size()-1; i++)
        {
            if(s[i] == '(' && s[i+1] == ')')
            {
                erased = true;
                s.erase(s.begin()+i+1);
                s.erase(s.begin()+i);
                break;
            }
        }
        // 다 지워졌으면 올바른 괄호 문자열임
        if(s.empty()) return true;
        // 지워지는 괄호 없으면 올바른 괄호 문자열이 아님
        if(!erased) return false;
    }
    return true;
}

string Sol(string w)
{
    // 1) 입력이 빈 문자열일 경우, 빈 문자열 반환
    if(w.empty()) return "";

    // 2) u, v 로 분리
    string u, v;
    // l = ( , r = )
    int l = 0, r = 0;
    int i;
    for(i = 0; i < w.size(); i++)
    {
        if(w[i] == '(') l++;
        else r++;
        u.push_back(w[i]);
        if(l == r) break;
    }
    v = w.substr(i+1);

    // 3)
    if(IsItCorrect(u))
    {
        string ret;
        ret = u + Sol(v);
        return ret;
    }
        // 4)
    else
    {
        string ret = "(";
        ret += Sol(v);
        ret += ")";

        u.erase(u.begin()+u.size()-1);
        u.erase(u.begin());
        for(int i = 0; i < u.size(); i++)
        {
            if(u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        ret += u;
        return ret;
    }

}

string solution(string p)
{
    return Sol(p);
}

int main()
{
    string p = "()";
    cout << "answer: " << solution(p);
}