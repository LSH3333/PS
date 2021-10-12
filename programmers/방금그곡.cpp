#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;


int CalTime(string begin, string end)
{
    int begin_hour = stoi(begin.substr(0, 2));
    int begin_min = stoi(begin.substr(3, 2));
    int end_hour = stoi(end.substr(0, 2));
    int end_min = stoi(end.substr(3, 2));
    return (end_hour * 60 + end_min) - (begin_hour * 60 + begin_min);
}

void ReplaceToSmall(string &s)
{
    for(int i = s.size(); i >= 0; i--)
    {
        if(s[i] == '#')
        {
            char to = (char)(s[i-1] + 32);
            string str = "";
            str = to;
            s.replace(i-1, 2, str);
        }
    }
}

string solution(string m, vector<string> musicinfos)
{
    string answer = "(None)";
    int answer_time = 0;
    ReplaceToSmall(m);

    for(int idx = 0; idx < musicinfos.size(); idx++)
    {
        string time_begin = "", time_end = "", title = "", note = "";
        stringstream ss(musicinfos[idx]);
        getline(ss, time_begin, ',');
        getline(ss, time_end, ',');
        getline(ss, title, ',');
        getline(ss, note, ',');

        ReplaceToSmall(note);
        int time = CalTime(time_begin, time_end);

        string newNote = "";
        int cursor = 0;
        for(int i = 0; i < time; i++)
        {
            newNote.push_back(note[cursor]);
            cursor = (cursor + 1) % note.size();
        }


        if(newNote.find(m) != string::npos && time > answer_time)
        {
            answer_time = time;
            answer = title;
        }
    }

    return answer;
}
