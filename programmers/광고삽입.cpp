#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// HH:MM:SS -> second
int ChangeToSecond(string time)
{
    string h = time.substr(0, 2);
    string m = time.substr(3, 2);
    string s = time.substr(6);

    return stoi(h) * 3600 + stoi(m) * 60 + stoi(s);
}

string ChangeToString(int time)
{
    int h = time / 3600;
    time %= 3600;
    int m = time / 60;
    time %= 60;
    int s = time;
//    cout << h << endl << m << endl << s << endl;

    string s_h = to_string(h);
    string s_m = to_string(m);
    string s_s = to_string(s);
    if(s_h.size() == 1) s_h = "0" + s_h;
    if(s_m.size() == 1) s_m = "0" + s_m;
    if(s_s.size() == 1) s_s = "0" + s_s;

    return s_h + ":" + s_m + ":" + s_s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int advTime = ChangeToSecond(adv_time);
    int playTime = ChangeToSecond(play_time);
    vector<pair<int,int>> timeLogs;
    for(auto x : logs)
    {
        int beginTime = ChangeToSecond(x.substr(0, 8));
        int endTime = ChangeToSecond(x.substr(9));
        timeLogs.push_back({beginTime, endTime});
    }

    sort(timeLogs.begin(), timeLogs.end());

//    for(auto x : timeLogs)
//    {
//        cout << x.first << ' ' << x.second << endl;
//    }
//    cout << "adv_time: " << advTime << endl << endl;

    int maxTotalTime = 0, returnTime = 0;
    for(int i = 0; i < timeLogs.size(); i++)
    {
        int beginTime = timeLogs[i].first;
        int endTime = beginTime + advTime;


//        cout << "beginTime: " << beginTime << endl;
//        cout << "endTime: " << endTime << endl;
        if(endTime > playTime) continue;

        long long totalTime = 0;
        for(int j = 0; j < timeLogs.size(); j++)
        {
            if(timeLogs[j].second < beginTime) continue;
            if(endTime < timeLogs[j].first) break;
            else if(timeLogs[j].second < beginTime) totalTime += 0;
            else if(beginTime <= timeLogs[j].first && timeLogs[j].second <= endTime)
            {
                totalTime += timeLogs[j].second - timeLogs[j].first;
            }
            else if(endTime <= timeLogs[j].second)
            {
                totalTime += endTime - timeLogs[j].first;
            }
            else if(timeLogs[j].first <= beginTime)
            {
                totalTime += timeLogs[j].second - beginTime;
            }
        }
//        cout << "totalTime: " << totalTime << endl << endl;

        if(totalTime > maxTotalTime)
        {
            maxTotalTime = totalTime;
            returnTime = beginTime;
        }
    }

//    cout << endl << "returnTime" << endl;
//    cout << returnTime << endl;
//
//    cout << "-----------" << endl;
//    cout << ChangeToString(returnTime);

    return ChangeToString(returnTime);
}

int main()
{
    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    vector<string> logs =
            {
                    "01:20:15-01:45:14",
                    "00:40:31-01:00:00",
                    "00:25:50-00:48:29",
                    "01:30:59-01:53:29",
                    "01:37:44-02:02:30"
            };

    string play_time2 = "99:59:59";
    string adv_time2 = "25:00:00";
    vector<string> logs2 =
            {
                    "69:59:59-89:59:59",
                    "01:00:00-21:00:00",
                    "79:59:59-99:59:59",
                    "11:00:00-31:00:00"
            };

    string play_time3 = "50:00:00";
    string adv_time3 = "50:00:00";
    vector<string> logs3 =
            {
                    "15:36:51-38:21:49",
                    "10:14:18-15:36:51",
                    "38:21:49-42:51:45"
            };

    solution(play_time3, adv_time3, logs3);
}