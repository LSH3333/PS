#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

int ChangeTime(string time)
{
    stringstream ss(time);
    string s_hour, s_min;
    getline(ss, s_hour, ':');
    getline(ss, s_min);

    return stoi(s_hour) * 60 + stoi(s_min);
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    deque<int> people, bus;
    for(int i = 0; i < timetable.size(); i++)
        people.push_back(ChangeTime(timetable[i]));
    sort(people.begin(), people.end());

    int nine = 540;
    for(int i = 0; i < n; i++)
    {
        bus.push_back(nine);
        nine += t;
    }
    int busSize = bus.size();


    for(int i = 0; i < busSize-1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(bus.front() >= people.front()) people.pop_front();
        }
        bus.pop_front();
    }
    
    int ans = 0;
    for(int i = 0; i < m-1; i++)
    {
        if(bus.front() >= people.front()) { people.pop_front(); }
    }
    if(people.empty()) ans = bus.front(); // 마지막 버스에 다 타고도 자리 남음
    else
    {
        if(people.front() > bus.front())
            ans = bus.front();
        else
            ans = people.front()-1;
    }

    // 분단위 -> 시간단위
    int hour = ans / 60;
    int min = ans % 60;
    string s_hour = to_string(hour);
    string s_min = to_string(min);
    if(s_hour.size() == 1) s_hour = "0" + s_hour;
    if(s_min.size() == 1) s_min = "0" + s_min;
    answer = s_hour + ":" + s_min;

    return answer;
}