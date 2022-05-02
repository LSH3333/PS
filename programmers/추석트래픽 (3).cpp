#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int ChangeToMS(string time)
{
    stringstream ss(time);
    string token;
    vector<string> t;
    while(getline(ss, token, ':')) t.push_back(token);

    int ms = 0;
    ms += stoi(t[0]) * 60 * 60 * 1000;
    ms += stoi(t[1]) * 60 * 1000;

    ss.str(t[2]);
    string _s = t[2].substr(0, t[2].find('.'));
    string _ms = t[2].substr(t[2].find('.')+1);

    ms += stoi(_s) * 1000;
    ms += stoi(_ms);

    return ms;
}

string ChangeTo2(int time)
{
    int h = time / (60 * 60 * 1000);
    time %= (60 * 60 * 1000);
    int m = time / (60 * 1000);
    time %= 60 * 1000;
    int s = time / (1000);
    time %= 1000;
    int ms = time;

    cout << h << ' ' << m << ' ' << s << ' ' << ms << endl;
}

int solution(vector<string> line)
{
    vector<pair<int, int>> timeline;
    for(const auto &l : line)
    {
        stringstream ss(l);
        string token;
        vector<string> v;
        while(ss >> token) v.push_back(token);
        int EndTime = ChangeToMS(v[1]);

        // s, ms
        string dur_s;
        string dur_ms;
        int i; v[2].pop_back();
        auto it = v[2].find('.');
        if(it != string::npos)
        {
            dur_s = v[2].substr(0, it);
            dur_ms = v[2].substr(it+1);
        }
        else
        {
            dur_s = v[2];
            dur_ms = "0";
        }

        int dur = stoi(dur_s) * 1000 + stoi(dur_ms);
        int BeginTime = EndTime - dur + 1;

        timeline.push_back({BeginTime, EndTime});
    }

    // print
//    for(auto x : timeline)
//    {
//        cout << x.first << ' ' << x.second << endl;
//    }

    int answer = 0;
    for(int i = 0; i < timeline.size(); i++)
    {
        int begin = timeline[i].first;
        int end = begin + 1000 - 1;
        int cnt = 0;
        for(int j = 0; j < timeline.size(); j++)
        {
            if(timeline[j].first > end || timeline[j].second < begin) continue;
            cnt++;
        }
//        cout << cnt << endl;
        answer = max(answer, cnt);
    }

    for(int i = 0; i < timeline.size(); i++)
    {
        int begin = timeline[i].second;
        int end = begin + 1000 - 1;
        int cnt = 0;
        for(int j = 0; j < timeline.size(); j++)
        {
            if(timeline[j].first > end || timeline[j].second < begin) continue;
            cnt++;
        }
//        cout << cnt << endl;
        answer = max(answer, cnt);
    }
    return answer;
}

int main()
{
    vector<string> line =
            {
                    "2016-09-15 01:00:04.001 2.0s",
                    "2016-09-15 01:00:07.000 2s"
            };
    solution(line);
}