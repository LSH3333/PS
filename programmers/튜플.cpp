#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<string,int> &a, const pair<string,int> &b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<string,int> m;

    // 앞뒤 괄호 제거
    s.pop_back();
    s.erase(s.begin());

    string temp = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            temp.push_back(s[i]);
        }
        else
        {
            if(!temp.empty())
            {
                m[temp]++;
                temp = "";
            }
        }
    }

    // value 기준 정렬 위해 vector로 변환
    vector<pair<string,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for(auto x : v) answer.push_back(stoi(x.first));

    return answer;
}

int main()
{
    string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
    solution(s);
}