#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer;

void CutString(int n, string s)
{
    reverse(s.begin(), s.end());

    vector<string> v;
    while(!s.empty())
    {
        int cnt = 0;
        string str;
        while(cnt < n && !s.empty())
        {
            str.push_back(s.back());
            s.pop_back();
            cnt++;
        }
        v.push_back(str);
    }

    // Make New String
    string newStr;
    int same = 1;
    for(int i = 0; i < v.size()-1; i++)
    {
        if(v[i] == v[i+1]) same++;
        else
        {
            if(same != 1) newStr += to_string(same);
            newStr += v[i];
            same = 1;
        }
    }
    if(same != 1) newStr += to_string(same);
    newStr += v.back();

    answer = min(answer, (int)newStr.size());
}

int solution(string s)
{
    answer = s.size();

    CutString(6, s);

    for(int i = 1; i <= (s.size()/2)+1; i++)
    {
        CutString(i, s);
    }

    return answer;
}

int main()
{
    string s = "ababcdcdababcdcd";
    solution(s);
}