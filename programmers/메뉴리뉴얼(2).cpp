#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<string,int> comb;

bool mark[30];
string str;

void InitSelect()
{
    for(int i = 0; i < 30; i++)
        mark[i] = false;
}

void MakeComb(string order, int course, int idx, int depth)
{
    if(depth == course)
    {
        comb[str]++;
        return;
    }

    for(int i = idx; i < order.size(); i++)
    {
        if(mark[i]) continue;
        mark[i] = true;
        str.push_back(order[i]);

        MakeComb(order, course, i, depth+1);
        mark[i] = false;
        str.pop_back();
    }

}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for(int i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());


    for(auto co : course)
    {
        for(auto order : orders)
        {
            MakeComb(order, co, 0, 0);
            InitSelect();
        }

        int biggest = 0;
        for(auto x : comb)
            biggest = max(biggest, x.second);

        for(auto x : comb)
        {
            if(x.second < 2) continue;
            if(x.second == biggest)
                answer.push_back(x.first);
        }

        comb.clear();
    }
    sort(answer.begin(), answer.end());

    return answer;
}