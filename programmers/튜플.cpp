#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool mark[100001];

bool cmp(const vector<string> &a, const vector<string> &b)
{
    return a.size() < b.size();
}

vector<int> solution(string s)
{
    vector<int> answer;

    vector<vector<string>> v;
    vector<string> tmp;
    string number;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9') number.push_back(s[i]);
        else if(s[i] == ',' && !number.empty()) { tmp.push_back(number); number = "";}
        else if(s[i] == '}' && !number.empty())
        {
            tmp.push_back(number);
            number = "";
            v.push_back(tmp);
            tmp.clear();
        }
    }

    sort(v.begin(), v.end(), cmp);

    for(auto i : v)
    {
        for(auto num : i)
        {
            int n = stoi(num);
            if(!mark[n])
            {
                answer.push_back(n);
                mark[n] = true;
            }
        }
    }

    return answer;
}
