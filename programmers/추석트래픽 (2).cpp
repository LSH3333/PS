#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int ChangeSToSecond(string time)
{
    string s_h = time.substr(0, 2);
    string s_m = time.substr(3, 2);
    string s_s = time.substr(6, 2);
    string s_ms = time.substr(9);

    int h = stoi(s_h)  * 60 * 60 * 1000;
    int m = stoi(s_m)  * 60 * 1000;
    int s = stoi(s_s)  * 1000;
    int ms = stoi(s_ms);
    return h + m + s + ms;
}

int ChangeTToSecond(string time)
{
    time.pop_back();
    double dur = stod(time) * 1000;
    return (int)dur;
}

int solution(vector<string> line)
{
    vector<pair<int,int>> times;
    for(auto x : line)
    {
        stringstream ss(x);
        string token;
        vector<string> v;
        while(ss >> token) v.push_back(token);

        int endTime = ChangeSToSecond(v[1]);
        int startTime = endTime - ChangeTToSecond(v[2]) + 1;
//        cout << startTime << ' ' << endTime << endl;
        times.push_back({startTime, endTime});
    }

    int answer = 0;
    for(int i = 0; i < times.size(); i++)
    {
        int startTime = times[i].first;
        int endTime = startTime + 1000 - 1;
        int cnt = 0;
        for(int j = 0; j < times.size(); j++)
        {
            // 요청시간과 요청마감시간이 1초 범위를 감싸고 있을때를 포함안함
//            if(times[j].first >= startTime && times[j].first <= endTime) cnt++;
//            else if(times[j].second >= startTime && times[j].second <= endTime) cnt++;
            if(times[j].second < startTime || times[j].first > endTime) continue;
            cnt++;
        }

        answer = max(answer, cnt);
    }

    for(int i = 0; i < times.size(); i++)
    {
        int startTime = times[i].second;
        int endTime = startTime + 1000 - 1;
        int cnt = 0;
        for(int j = 0; j < times.size(); j++)
        {
//            if(times[j].first >= startTime && times[j].first <= endTime) cnt++;
//            else if(times[j].second >= startTime && times[j].second <= endTime) cnt++;
            if(times[j].second < startTime || times[j].first > endTime) continue;
            cnt++;
        }
        answer = max(answer,cnt);
    }

//    cout << endl;
//    cout << answer;
    return answer;
}

int main()
{
    vector<string> line =
            {
                    "2016-09-15 20:59:57.421 0.351s",
                    "2016-09-15 20:59:58.233 1.181s",
                    "2016-09-15 20:59:58.299 0.8s",
                    "2016-09-15 20:59:58.688 1.041s",
                    "2016-09-15 20:59:59.591 1.412s",
                    "2016-09-15 21:00:00.464 1.466s",
                    "2016-09-15 21:00:00.741 1.581s",
                    "2016-09-15 21:00:00.748 2.31s",
                    "2016-09-15 21:00:00.966 0.381s",
                    "2016-09-15 21:00:02.066 2.62s"
            };

    vector<string> line2 =
            {
                    "2016-09-15 01:00:04.002 2.0s",
                    "2016-09-15 01:00:07.000 2s"
            };
    vector<string> line4 =
            {
                    "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"
            };
    solution(line4);
//    solution(line2);
}