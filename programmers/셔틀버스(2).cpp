#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int ChangeToMinute(string time)
{
    string s_h = time.substr(0,2);
    string s_m = time.substr(3, 2);
    int h = stoi(s_h);
    int m = stoi(s_m);
    return h * 60 + m;
}

string ChangeToHour(int time)
{
    int h = time / 60;
    int m = time % 60;
    string s_h = to_string(h);
    string s_m = to_string(m);
    if(s_h.size() == 1) s_h = "0" + s_h;
    if(s_m.size() == 1) s_m = "0" + s_m;
    return s_h + ":" + s_m;
}

string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";
    vector<int> crewTime, busTime;
    for(auto x : timetable) crewTime.push_back(ChangeToMinute(x));
    int nine = 540;
    for(int i = 0; i < n; i++)
    {
        busTime.push_back(nine);
        nine += t;
    }
    // 내림차순 정렬
    sort(crewTime.begin(), crewTime.end(), greater<>());
    sort(busTime.begin(), busTime.end(), greater<>());

    int busSize = busTime.size();
    // 마지막 버스 전까지 다 태워보냄
    for(int i = 0; i < busSize-1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(crewTime.back() <= busTime.back() && !crewTime.empty())
                crewTime.pop_back();
        }
        busTime.pop_back();
    }

    // 마지막 버스 시간
    int lastBusTime = busTime.front();
    sort(crewTime.begin(), crewTime.end());
    vector<int> lastBus;
    // 마지막 버스에 m명 태운다
    for(int i = 0; i < m; i++)
    {
        if(i >= crewTime.size()) break;
        if(crewTime[i] > lastBusTime) break;
        if(crewTime[i] <= lastBusTime)
            lastBus.push_back(crewTime[i]);
    }

    int ansTime = 0;
    // 마지막 버스에 자리가 있을 때
    if(lastBus.size() < m)
    {
        ansTime = lastBusTime; // 마지막 버스 시간에 오면됨
    }
    else // 마지막 버스에 자리가 없을 떄
    {
        int lastCrewTime = lastBus.back();
        // 마지막 크루 1분 전에 오면 됨
        ansTime = lastCrewTime - 1;
    }

    answer = ChangeToHour(ansTime);
    return answer;
}

int main()
{
    vector<string> timetable =
            {
                    "00:01", "00:01", "00:01","00:01", "00:01", "00:02", "00:03", "00:04"
            };
    solution(1,1,5,timetable);

}