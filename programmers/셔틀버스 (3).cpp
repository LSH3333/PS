#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int ChangeToMin(string time)
{
    string h = time.substr(0, 2);
    string m = time.substr(3);
    return stoi(h) * 60 + stoi(m);
}

string ChangeToStr(int time)
{
    int h = time / 60;
    int m = time % 60;
    string h_s = to_string(h);
    string m_s = to_string(m);
    if(h_s.size() == 1) h_s = "0" + h_s;
    if(m_s.size() == 1) m_s = "0" + m_s;
    return h_s + ":" + m_s;
}

string solution(int n, int t, int m, vector<string> timetable)
{
    // people time
    deque<int> ppl;
    for(auto x : timetable)
    {
        ppl.push_back(ChangeToMin(x));
    }
    sort(ppl.begin(), ppl.end());

    // bus time
    deque<int> bus;
    int nine = 540;
    for(int i = 0; i < n; i++)
    {
        bus.push_back(nine);
        nine += t;
    }

//    cout << "bus: ";
//    for(auto x : bus) cout << x << ' '; cout << endl;
//    cout << "ppl: ";
//    for(auto x : ppl) cout << x << ' '; cout << endl << endl;


    // 마지막 버스 전 버스까지다 보냄
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!ppl.empty() && ppl.front() <= bus.front()) ppl.pop_front();
        }
        bus.pop_front();
    }

    // 마지막 버스에서는 한 자리만 남기고 다 보냄
    for(int i = 0; i < m-1; i++)
    {
        if(!ppl.empty() && ppl.front() <= bus.front()) ppl.pop_front();
    }

    int answer;
    // 줄 서 있는 사람 없으면, 마지막 버스오는 시간에 오면됨
    if(ppl.empty()) answer = bus.front();
    // 줄 맨 앞 사람이 버스 시간과 같거나 더 일찍 왔을때는 그 사람보다 1분 빨리와야함
    else if(ppl.front() <= bus.front()) answer = ppl.front()-1;
    // 줄 맨 앞 사람이 버스 시간보다 늦게 왔다면, 버스 시간과 같은 시간에 도착하면됨
    else answer = bus.front();


//    cout << "bus: ";
//    for(auto x : bus) cout << x << ' '; cout << endl;
//    cout << "ppl: ";
//    for(auto x : ppl) cout << x << ' '; cout << endl;
//    cout << ChangeToStr(answer);

    return ChangeToStr(answer);
}

int main()
{
    int n = 10;
    int t = 60;
    int m = 45;
    vector<string> timetable =
            {
                    "23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"
            };
    solution(n, t, m, timetable);
}