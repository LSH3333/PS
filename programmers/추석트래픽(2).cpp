#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<pair<int,int>> v;

void CalculateBeginTime(string endTime, string duration)
{
    stringstream ss(endTime);
    string s_h, s_m, s_s;
    getline(ss, s_h, ':');
    getline(ss, s_m, ':');
    getline(ss, s_s);

    double d_s = stod(s_s) * 1000;
    int i_s = (int)d_s;
    int i_endTime = i_s + (stoi(s_m) * 60 * 1000) + (stoi(s_h) * 1000 * 60 * 60);
    double d_duration = stod(duration) * 1000;
    int i_duration = (int)d_duration;
    int i_beginTime = i_endTime - i_duration + 1;

    v.push_back({i_beginTime, i_endTime});
}

int solution(vector<string> line)
{


    for(int i = 0; i < line.size(); i++)
    {
        stringstream ss(line[i]);
        string time, duration;
        string token;
        int cnt = 0;
        while(ss >> token)
        {
            switch(cnt++)
            {
                case 1:
                    time = token;
                    break;
                case 2:
                    duration = token;
                    break;
            }
        }

        CalculateBeginTime(time, duration);
    }

    int answer = 0;
    for(int i = 0; i < v.size(); i++)
    {
        //
        int cnt = 0;
        int x = v[i].first;
        int y = x + 1000 - 1;

        for(int j = 0; j < v.size(); j++)
        {
            if(v[j].second < x || v[j].first > y) continue;
            cnt++;
        }

        answer = max(answer, cnt);

        //
        cnt = 0;
        x = v[i].second;
        y = x + 1000 - 1;

        for(int j = 0; j < v.size(); j++)
        {
            if(v[j].second < x || v[j].first > y) continue;
            cnt++;
        }

        answer = max(answer, cnt);
    }
    return answer;
}
