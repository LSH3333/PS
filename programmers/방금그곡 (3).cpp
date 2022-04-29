#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int ChangeToMin(string time)
{
    string h = time.substr(0, 2);
    string m = time.substr(3);
    return stoi(h) * 60 + stoi(m);
}

string ChangeToStr(int time)
{
    int h = time / 60;
    int m = time % 60;
    string h_s = to_string(h);
    string m_s = to_string(m);
    if(h_s.size() == 1) h_s = "0" + h_s;
    if(m_s.size() == 1) m_s = "0" + m_s;
    return h_s + ":" + m_s;
}

string solution(string m, vector<string> musicinfos)
{
    // name, music
    vector<pair<string,string>> v;

    string m2;
    for(int i = 0; i < m.size()-1; i++)
    {
        if(m[i] == '#') continue;
        if(m[i+1] == '#') m2.push_back(tolower(m[i]));
        else m2.push_back(m[i]);
    }
    if(m.back() != '#') m2.push_back(m.back());

    string answer = "(None)";
    int maxTime = 0;

    for(auto music : musicinfos)
    {
        // 문자열 분리
        vector<string> info;
        stringstream ss(music);
        for(int i = 0; i < 4; i++)
        {
            string str;
            getline(ss, str, ',');
            info.push_back(str);
        }

//        for(auto x : info) cout << x<< ' '; cout << endl;
        // 악보 생성
        string mus;
        for(int i = 0; i < info[3].size()-1; i++)
        {
            if(info[3][i] == '#') continue;
            if(info[3][i+1] == '#') mus.push_back(tolower(info[3][i]));
            else mus.push_back(info[3][i]);
        }
        if(info[3].back() != '#') mus.push_back(info[3].back());

        int time = ChangeToMin(info[1]) - ChangeToMin(info[0]);
        string mus2;
        for(int i = 0; i < time; i++)
        {
            int idx = i % mus.size();
            mus2.push_back(mus[idx]);
        }

        // 조건 일치
        if(mus2.find(m2) != string::npos && time > maxTime)
        {
            answer = info[2];
            maxTime = time;
        }
    }

    return answer;
}

int main()
{
    string m = "ABC";
    vector<string> musicinfos =
            {
                    "12:00,12:14,HELLO,C#DEFGAB",
                    "13:00,13:05,WORLD,ABCDEF"
            };
    solution(m, musicinfos);

}
