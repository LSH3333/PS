#include <string>
#include <vector>
#include <iostream>
using namespace std;

int CheckTime(string begin, string end)
{
    string beginH = "";
    beginH = begin[0]; beginH.push_back(begin[1]);
    string beginM = "";
    beginM = begin[3]; beginM.push_back(begin[4]);

    string endH = "";
    endH = end[0]; endH.push_back(end[1]);
    string endM = "";
    endM = end[3]; endM.push_back(end[4]);

    return (60 * stoi(endH) + stoi(endM)) - (60 * stoi(beginH) + stoi(beginM));
}

string CheckMus(string &mus)
{
    string ret = "";
    for(int i = 0; i < mus.size()-1; i++)
    {
        if(mus[i+1] == '#') {ret.push_back((char)tolower(mus[i])); i++;}
        else ret.push_back(mus[i]);
    }
    if(mus.back() != '#') ret.push_back(mus.back());
    return ret;
}

string solution(string m, vector<string> musicinfos)
{
    string ans = "";
    int ansSize = 0;
    m = CheckMus(m);

    for(int idx = 0; idx < musicinfos.size(); idx++)
    {
        vector<string> v;
        string str = "";
        for(int i = 0; i < musicinfos[idx].size(); i++)
        {
            char cur = musicinfos[idx][i];
            if(cur == ',') { v.push_back(str); str = ""; continue; }
            str.push_back(cur);
        }
        v.push_back(str);

        ////
        int time = CheckTime(v[0], v[1]);
        string music = CheckMus(v[3]);

        string fullMusic = "";
        for(int i = 0; i < time; i++) fullMusic += music[i % music.size()];

        if(fullMusic.find(m, 0) != string::npos && time > ansSize)
        {
            ans = v[2];
            ansSize = time;
        }
    }

    if(ans.empty()) return "(None)";
    return ans;
}