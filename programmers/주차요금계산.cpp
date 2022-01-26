#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int TimeStringToInt(string time)
{
    int h = stoi(time.substr(0,2));
    int m = stoi(time.substr(3,2));
    return h * 60 + m;
}

bool cmd(const string &a, const string &b)
{
    int aNum = stoi(a.substr(6,4));
    int bNum = stoi(b.substr(6,4));
    if(aNum == bNum)
    {
        int aTime = TimeStringToInt(a.substr(0,5));
        int bTime = TimeStringToInt(b.substr(0,5));
        return aTime < bTime;
    }
    return aNum < bNum;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    map<string, int> m;
    sort(records.begin(), records.end(), cmd);

    if(records.size() == 1)
    {
        int dur = TimeStringToInt("23:59") - TimeStringToInt(records[0].substr(0,5));
        m[records[0].substr(6,4)] += dur;
    }
    else
    {
        for(int i = records.size()-1; i >= 0;)
        {
            // OUT
            if(records[i][11] == 'O')
            {
                int dur = TimeStringToInt(records[i].substr(0, 5)) - TimeStringToInt(records[i-1].substr(0,5));
                m[records[i].substr(6,4)] += dur;
                i -= 2;
            }
                // IN (출차기록 없음, 23:59에 출차)
            else
            {
                int dur = TimeStringToInt("23:59") - TimeStringToInt(records[i].substr(0,5));
                m[records[i].substr(6,4)] += dur;
                i -= 1;
            }
        }
    }

    for(auto x : m)
    {
        if(x.second <= fees[0]) {answer.push_back(fees[1]); continue;}
        int fee = fees[1];
        if((x.second - fees[0]) % fees[2] != 0)
        {
            fee += (((x.second - fees[0]) / fees[2]) + 1) * fees[3];
        }
        else
            fee += ((x.second - fees[0]) / fees[2]) * fees[3];

        answer.push_back(fee);
    }

    return answer;
}