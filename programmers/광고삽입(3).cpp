#include <vector>
#include <string>
#include <iostream>
using namespace std;

int times[360010];

int StringToInt(string time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6));
    return h * 3600 + 60 * m + s;
}

string IntToString(int time)
{
    string h = to_string(time / 3600);
    time %= 3600;
    string m = to_string(time / 60);
    time %= 60;
    string s = to_string(time);
    if(h.size() == 1) h = "0" + h;
    if(m.size() == 1) m = "0" + m;
    if(s.size() == 1) s = "0" + s;
    return h + ":" + m + ":" + s;
}

string solution(string play_time, string adv_time, vector<string> logs)
{
    for(auto x : logs)
    {
        int beginTime = StringToInt(x.substr(0,8));
        int endTime = StringToInt(x.substr(9));
        for(int i = beginTime; i < endTime; i++) times[i]++;
    }

    int playTime = StringToInt(play_time);
    int advTime = StringToInt(adv_time);
    long long curTime = 0;
    for(int i = 0; i < advTime; i++)
    {
        curTime += times[i];
    }

    long long maxTime = curTime;
    int answerTime = 0;
    for(int i = advTime; i < playTime; i++)
    {
        curTime -= times[i-advTime];
        curTime += times[i];
        if(curTime > maxTime)
        {
            curTime = maxTime;
            answerTime = i-advTime+1;
        }
    }

    return IntToString(answerTime);
}
