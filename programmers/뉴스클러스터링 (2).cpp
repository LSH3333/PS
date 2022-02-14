#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(string str1, string str2)
{
    for(int i = 0; i < str1.size(); i++) str1[i] = tolower(str1[i]);
    for(int i = 0; i < str2.size(); i++) str2[i] = tolower(str2[i]);

    map<string, int> map1, map2;
    vector<string> s1, s2;
    for(int i = 0; i < str1.size()-1; i++)
    {
        if(str1[i] >= 'a' && str1[i] <= 'z')
        {
            if(str1[i+1] >= 'a' && str1[i+1] <= 'z')
            {
                string s = ""; s.push_back(str1[i]); s.push_back(str1[i+1]);
                s1.push_back(s);
                map1[s]++;
            }
        }
    }

    for(int i = 0; i < str2.size()-1; i++)
    {
        if(str2[i] >= 'a' && str2[i] <= 'z')
        {
            if(str2[i+1] >= 'a' && str2[i+1] <= 'z')
            {
                string s = ""; s.push_back(str2[i]); s.push_back(str2[i+1]);
                s2.push_back(s);
                map2[s]++;
            }
        }
    }
    int totalCnt = s1.size() + s2.size();
    if(totalCnt == 0) return 65536;
//    cout << "totalCnt: " << totalCnt << endl;
//
//    for(auto x : s1) cout << x << ' '; cout << endl;
//    for(auto x : s2) cout << x << ' '; cout << endl << endl;
//    for(auto x : map1) cout << x.first << ' ' << x.second << endl; cout << endl;
//    for(auto x : map2) cout << x.first << ' ' << x.second << endl;

    int interCnt = 0, unionCnt = 0;


    for(auto x : map1)
    {
        interCnt += min(x.second, map2[x.first]);
    }
    unionCnt = totalCnt - interCnt;
//    cout << interCnt << ' ' << unionCnt << endl;

    double a = interCnt;
    double b = unionCnt;
    double answer_d = (a / b) * 65536;
    int answer = (int)answer_d;
//    cout << answer;
    return answer;
}

int main()
{
    string str1 = "E=M*C^2";
    string str2 = "e=m*c^2";
    solution(str1, str2);
}