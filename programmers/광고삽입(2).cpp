#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int a[360000];

int StringToInt(string time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3,2));
    int s = stoi(time.substr(6));
    return h * 3600 + m * 60 + s;
}

string IntToString(int time)
{
    string h = to_string(time / 3600);
    time %= 3600;
    string m = to_string(time / 60);
    time %= 60;
    string s = to_string(time);

    h = h.size() == 1 ? "0"+h : h;
    m = m.size() == 1 ? "0"+m : m;
    s = s.size() == 1 ? "0"+s : s;
    return h + ":" + m + ":" + s;
}

string solution(string play_time, string adv_time, vector<string> logs)
{
    for(auto x : logs)
    {
        int beginTime = StringToInt(x.substr(0, 8));
        int endTime = StringToInt(x.substr(9));
        for(int i = beginTime; i < endTime; i++) a[i]++;
    }

    int playTime = StringToInt(play_time);
    int advTime = StringToInt(adv_time);

    long long time = 0;
    long long maxTime = 0;
    int answerBeginTime = 0;
    for(int i = 0; i < advTime; i++) time += a[i];
    maxTime = time;

    for(int i = advTime; i < playTime; i++)
    {
        time += a[i];
        time -= a[i-advTime];

        if(time > maxTime)
        {
            answerBeginTime = i - advTime + 1;
            maxTime = time;
        }
    }

//    cout << answerBeginTime << endl;
//    cout << IntToString(answerBeginTime);

    return IntToString(answerBeginTime);
}
