#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int ChangeToMinute(string time)
{
    string s_h = time.substr(0,2);
    string s_m = time.substr(3);
    return 60 * stoi(s_h) + stoi(s_m);
}

string ChangeSharp(string note)
{
    string changed = "";
    for(int i = 0; i < note.size()-1; i++)
    {
        if(note[i] == '#') continue;
        if(note[i+1] == '#')
        {
            changed += tolower(note[i]);
        }
        else
        {
            changed += note[i];
        }
    }
    if(note.back() != '#') changed += note.back();
    return changed;
}

string solution(string m, vector<string> musicinfos)
{
    string answer = "(None)";
    int maxDur = 0;
    m = ChangeSharp(m);

    for(auto musicinfo : musicinfos)
    {
        stringstream ss(musicinfo);
        string beginTime, endTime, title, notes;
        getline(ss, beginTime, ',');
        getline(ss, endTime, ',');
        getline(ss, title, ',');
        getline(ss, notes);

        // 곡 재생 시간
        int dur = ChangeToMinute(endTime) - ChangeToMinute(beginTime);
        // # 노트는 소문자로 변경
        notes = ChangeSharp(notes);

        string newNotes = notes;
        int idx = 0;
        // 재생시간이 음악시간보다 짧은 경우
        if(dur <= notes.size())
        {
            newNotes = notes.substr(0, dur);
        }
            // 재생시간이 음악시간보다 긴 경우
        else
        {
            while(newNotes.size() < dur)
            {
                newNotes.push_back(notes[idx]);
                idx = (idx + 1) % notes.size();
            }
        }

        int findRes = newNotes.find(m);
        // 문자열 존재
        if(findRes != string::npos && dur > maxDur)
        {
            answer = title;
            maxDur = dur;
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

    string m2 = "CC#BCC#BCC#BCC#B";
    vector<string> musicinfos2 =
            {
                    "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"
            };
    solution(m2, musicinfos2);
}