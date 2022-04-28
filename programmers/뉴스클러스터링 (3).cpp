#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

bool Check(string str)
{
    if(str[0] < 'a' || str[0] > 'z') return false;
    if(str[1] < 'a' || str[1] > 'z') return false;
    return true;
}

vector<string> MakeStr(string str)
{
    for(auto &x : str) x = tolower(x);

    vector<string> v;
    for(int i = 0; i < str.size()-1; i++)
    {
        string s = str.substr(i, 2);
        if(Check(s)) v.push_back(s);
    }

    return v;
}

int solution(string str1, string str2)
{
    vector<string> v1 = MakeStr(str1);
    vector<string> v2 = MakeStr(str2);

    unordered_map<string, int> m1;
    unordered_map<string, int> m2;
    set<string> sets;
    for(const auto &x : v1) { m1[x]++; sets.insert(x); }
    for(const auto &x : v2) { m2[x]++; sets.insert(x); }


    int a = 0, b = 0;
    for(auto x : sets)
    {
        a += min(m1[x], m2[x]);
        b += max(m1[x], m2[x]);
    }
//    cout << a << ' ' << b << endl;

    double answer;
    if(a == 0 && b == 0) answer = 65536;
    else answer = (double)a / b * 65536;


    return (int)answer;
}

int main()
{
    string str1 = "handshake";
    string str2 = "shake hands";

//    string str1 = "FRANCE";
//    string str2 = "french";
    solution(str1, str2);
}