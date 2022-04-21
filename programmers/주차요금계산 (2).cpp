#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
using namespace std;

int ChangeToMin(string time)
{
    string h = time.substr(0, 2);
    string m = time.substr(3);
    int h_i = stoi(h);
    int m_i = stoi(m);
    return h_i * 60 + m_i;
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<pair<int, string>> v;
    map<string, int> m;
    for(auto x : records)
    {
        int time = ChangeToMin(x.substr(0, 5));
        string car = x.substr(6, 4);
        v.push_back({time, car});
    }

//    for(auto x : v)
//    {
//        cout << x.first << ' ' << x.second << endl;
//    } cout << endl;

    for(int i = 0; i < v.size(); i++)
    {
        int time = v[i].first;
        string car = v[i].second;
        if(time == -1) continue;

        int dur = 0;
        bool found = false;
        for(int j = i+1; j < v.size(); j++)
        {
            if(v[j].second == car)
            {
                found = true;
                dur = v[j].first - v[i].first;
                v[j].first = -1; // 사용 기록함
                break;
            }
        }
        // 출차 기록 없음
        if(!found) dur = ChangeToMin("23:59") - time;
        m[car] += dur;
    }

    vector<int> answer;
    for(auto x : m)
    {
        int time = x.second;
        int cost = 0;
        if(time <= fees[0]) cost = fees[1];
        else
        {
            double div = fees[2];
            cost = fees[1] + ceil((time-fees[0])/div) * fees[3];
        }
        answer.push_back(cost);
    }

    return answer;
}

int main()
{
    vector<int> fees = {1, 461, 1, 10};
    vector<string> records =
            {
                    "00:00 1234 IN"
            };
    solution(fees, records);
}