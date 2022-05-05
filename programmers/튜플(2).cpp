#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool mark[100001];

vector<vector<int>> DivideStr(const string &s)
{
    vector<vector<int>> v;
    vector<int> tmp;
    string number;
    for(auto x : s)
    {
        if(x >= '0' && x <= '9') number.push_back(x);
        else if(x == ',' && !number.empty())
        {
            tmp.push_back(stoi(number));
            number.clear();
        }
        else if(x == '}' && !number.empty())
        {
            tmp.push_back(stoi(number));
            v.push_back(tmp);
            number.clear();
            tmp.clear();
        }
    }
    return v;
}

bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a.size() < b.size();
}


vector<int> solution(string s)
{
    vector<vector<int>> v = DivideStr(s);
    sort(v.begin(), v.end(), cmp);
    for(auto &x : v) sort(x.begin(), x.end());


//    for(auto x : v)
//    {
//        for(auto y : x) cout << y << ' ';
//        cout << endl;
//    }

    vector<int> answer;
    for(auto x : v)
    {
        for(auto y : x)
        {
            if(!mark[y])
            {
                answer.push_back(y);
                mark[y] = true;
                break;
            }
        }
    }

//    cout << endl;
//    for(auto x : answer) cout << x << ' ';

    return answer;
}

int main()
{
    string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
    solution(s);
}