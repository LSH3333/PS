#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ChangeToSec(string time)
{
    string m = time.substr(0, 2);
    string s = time.substr(3);
    int m_int = stoi(m);
    int s_int = stoi(s);
    return m_int * 60 + s_int;
}

string ChangeToMin(int time)
{
    int m = time / 60;
    int s = time % 60;
    string m_str = to_string(m);
    string s_str = to_string(s);
    if(m_str.size() == 1) m_str = "0" + m_str;
    if(s_str.size() == 1) s_str = "0" + s_str;
    return m_str + ":" + s_str;
}

int main()
{
    int N; cin >> N;
    vector<pair<int,int>> goal;
    int team;
    string time;
    for(int i = 0; i < N; i++)
    {
        cin >> team >> time;
        goal.push_back({team, ChangeToSec(time)});
    }
    // 끝나는 시간
    goal.push_back({0, 60*48});

    int t1 = 0, t2 = 0;
    vector<pair<pair<int,int>,int>> v;
    for(int i = 0; i < N; i++)
    {
        if(goal[i].first == 1) t1++; else t2++;
        if(t1 == t2) continue;
        int winning = t1 > t2 ? 1 : 2;
        v.push_back({{goal[i].second, goal[i+1].second}, winning});
    }

    int t1Time = 0, t2Time = 0;
    for(auto x : v)
    {
        if(x.second == 1) t1Time += x.first.second - x.first.first;
        else t2Time += x.first.second - x.first.first;
    }

    cout << ChangeToMin(t1Time) << '\n' << ChangeToMin(t2Time);
}