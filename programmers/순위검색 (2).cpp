#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

map<string, vector<int>> m;

void MakeComb(vector<string>& v, vector<bool> &mark, int idx, int depth, int cnt, int score)
{
    if(depth == cnt)
    {
        string str;
        for(int i = 0; i < 4; i++)
        {
            if(mark[i]) str += '-';
            else str += v[i];
        }
//        cout << str << ' ' << score << endl;
        m[str].push_back(score);
        return;
    }

    for(int i = idx; i < 4; i++)
    {
        if(mark[i]) continue;
        mark[i] = true;
        MakeComb(v, mark, i, depth+1, cnt, score);
        mark[i] = false;
    }
}

vector<int> solution(vector<string> info, vector<string> query)
{
    // info
    for(auto in : info)
    {
        stringstream ss(in);
        string token;
        vector<string> v;
        while(ss >> token) v.push_back(token);
        int score = stoi(v.back());
        v.pop_back();

        for(int i = 0; i <= 4; i++)
        {
            vector<bool> mark(4, false);
            MakeComb(v, mark, 0, 0, i, score);
        }
//        cout << endl << endl;
    }

    // 점수 오름 차순 정렬
    for(auto &x : m)
    {
        sort(x.second.begin(), x.second.end());
    }

//    for(auto x : m)
//    {
//        cout << x.first << endl;
//        for(auto y : x.second) cout << y << ' '; cout << endl;
//    }

    vector<int> answer;
    // query
    for(auto q : query)
    {
        stringstream ss(q);
        string token;
        string str;
        vector<string> v;
        while(ss >> token)
        {
            if(token == "and") continue;
            v.push_back(token);
        }
        int score = stoi(v.back());
        v.pop_back();
        for(const auto &x : v) str += x;


//        cout << "str: " << str << endl;
        int idx = lower_bound(m[str].begin(), m[str].end(), score) - m[str].begin();
        answer.push_back(m[str].size()-idx);
    }

//    for(auto x : answer) cout << x<< ' ';
    return answer;
}

int main()
{
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    solution(info, query);
}