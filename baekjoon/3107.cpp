#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string ip; cin >> ip;
    vector<string> v;
    stringstream ss(ip);
    string str;
    while(getline(ss, str, ':'))
    {
        v.push_back(str);
    }

    // 축약 시작점, 몇개 축약 됐는지 탐색
    int emptyIdx = 0;
    int emptySize = 0, notEmptySize = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].empty())
        {
            emptyIdx = i; break;
        }
    }

    for(int i = 0; i < v.size(); i++)
    {
        if(!v[i].empty()) notEmptySize++;
    }
    emptySize = 8 - notEmptySize;



    vector<string> answer;
    for(auto x : v)
    {
        if(!x.empty()) answer.push_back(x);
    }
    answer.insert(answer.begin()+emptyIdx, emptySize, "0000");

    for(int i = 0; i < answer.size(); i++)
    {
        if(answer[i].size() < 4)
        {
            answer[i].insert(answer[i].begin(), 4-answer[i].size(), '0');
        }
    }

    for(int i = 0; i < answer.size()-1; i++)
    {
        cout << answer[i] << ":";
    }
    cout << answer.back();
}