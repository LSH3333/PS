#include <iostream>
#include <string>
#include <vector>
using namespace std;

int times[360100];

int StrToInt(string time)
{
    string h = time.substr(0, 2);
    string m = time.substr(3, 2);
    string s = time.substr(6);
    return stoi(s) + stoi(m) * 60 + stoi(h) * 3600;
}

string LLToStr(long long time)
{
    long long h, m, s;
    h = time / 3600;
    time %= 3600;
    m = time / 60;
    time %= 60;
    s = time;

    string h_s = to_string(h);
    string m_s = to_string(m);
    string s_s = to_string(s);
    if(h_s.size() == 1) h_s = "0" + h_s;
    if(m_s.size() == 1) m_s = "0" + m_s;
    if(s_s.size() == 1) s_s = "0" + s_s;
    return h_s + ":" + m_s + ":" + s_s;
}

string solution(string play_time, string adv_time, vector<string> logs)
{
    for(const auto &log : logs)
    {
        int begin = StrToInt(log.substr(0, 8));
        int end = StrToInt(log.substr(9));
        for(int i = begin; i < end; i++) times[i]++;
    }

    int pTime = StrToInt(play_time);
    int advTime = StrToInt(adv_time);
    long long sum = 0;
    for(int i = 0; i < advTime; i++) sum += times[i];

    //
    long long maxSum = sum; int answerTime = 0;
    for(int i = advTime; i < pTime; i++)
    {
        sum += times[i];
        sum -= times[i-advTime];
        if(sum > maxSum)
        {
            maxSum = sum;
            answerTime = i - advTime + 1;
        }
    }


//    cout << endl << IntToStr(answerTime) << endl;
    return LLToStr(answerTime);
}

int main()
{
    string play_time = "50:00:00";
    string adv_time = "50:00:00";
    vector<string> logs =
            {
                    "15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"
            };
    solution(play_time, adv_time, logs);
}