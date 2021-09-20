#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    // 대문자로 통일
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] >= 'a' && str1[i] <= 'z')
        {
            str1[i] = toupper(str1[i]);
        }
    }
    for(int i = 0; i < str2.size(); i++)
    {
        if(str2[i] >= 'a' && str2[i] <= 'z')
        {
            str2[i] = toupper(str2[i]);
        }
    }

    // 문자열 나누기
    map<string,int> m1, m2;
    for(int i = 0; i < str1.size()-1; i++)
    {
        if(!(str1[i] >= 'A' && str1[i] <= 'Z')) continue;
        if(!(str1[i+1] >= 'A' && str1[i+1] <= 'Z')) continue;
        string temp = "";
        temp.push_back(str1[i]);
        temp.push_back(str1[i+1]);
        m1[temp]++;
    }
    for(int i = 0; i < str2.size()-1; i++)
    {
        if(!(str2[i] >= 'A' && str2[i] <= 'Z')) continue;
        if(!(str2[i+1] >= 'A' && str2[i+1] <= 'Z')) continue;
        string temp = "";
        temp.push_back(str2[i]);
        temp.push_back(str2[i+1]);
        m2[temp]++;
    }

    int unionCnt = 0, intersectionCnt = 0;
    vector<string> v;
    for(auto x : m1) v.push_back(x.first);
    for(auto x : m2) v.push_back(x.first);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(auto x : v)
    {
        unionCnt += max(m1[x], m2[x]);
        intersectionCnt += min(m1[x], m2[x]);
    }

    if(unionCnt == 0) return 65536;
    double ans = (double)intersectionCnt / (double)unionCnt * 65536;

    return ans;
}
