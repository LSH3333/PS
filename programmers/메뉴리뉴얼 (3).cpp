#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<string,int> m;

void MakeComb(string order, vector<bool> &mark, int idx, int depth, string &str, int cnt)
{
    if(depth == cnt)
    {
        m[str]++;
        return;
    }

    for(int i = idx; i < order.size(); i++)
    {
        if(mark[i]) continue;
        mark[i] = true;
        str.push_back(order[i]);
        MakeComb(order, mark, i, depth+1, str, cnt);
        mark[i] = false;
        str.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    string menus = "";
    for(auto &x : orders)
    {
        sort(x.begin(), x.end());
    }

    vector<string> answer;
    for(auto cnt : course)
    {
        for(auto order : orders)
        {
            if(order.size() < cnt) continue;
            vector<bool> mark(order.size(), false);
            string str = "";
            MakeComb(order, mark, 0, 0, str, cnt);
        }

//        for(auto x : m) cout << x.first << ' ' << x.second << endl;
//        cout << endl;

        int maxCnt = 0;
        for(const auto &x : m) maxCnt = max(maxCnt, x.second);

        if(maxCnt >= 2)
        {
            for(const auto &x : m)
            {
                if(x.second == maxCnt) answer.push_back(x.first);
            }
        }

        m.clear();
    }

    for(auto &x : answer) sort(x.begin(), x.end());
    sort(answer.begin(), answer.end());
//    for(auto x : answer) cout << x << ' '; cout << endl;
    return answer;
}

int main()
{
    vector<string> orders = {"XYZ", "XWY", "WXA"};
    vector<int> course = {2,3,4};
    solution(orders, course);
}