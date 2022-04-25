#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int CutString(string s, int n)
{
    vector<string> v;
    reverse(s.begin(), s.end());

    while(!s.empty())
    {
        string str;
        while(str.size() < n && !s.empty())
        {
            str.push_back(s.back());
            s.pop_back();
        }
        v.push_back(str);
    }
//    for(auto x : v) cout << x << ' ';
    //
    string newStr;
    int same = 1;
    for(int i = 0; i < v.size()-1; i++)
    {
        if(v[i] == v[i+1]) same++;
        else
        {
            if(same == 1) newStr += v[i];
            else newStr += to_string(same) + v[i];
            same = 1;
        }
    }
    if(same != 1) newStr += to_string(same);
    newStr += v.back();

    return newStr.size();
}

int solution(string s)
{

    int answer = 9999;
    for(int i = 1; i <= s.size(); i++)
    {
        answer = min(answer, CutString(s, i));
    }
    return answer;
}

int main()
{
    solution("abcabcdede");
}