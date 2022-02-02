#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;

    unordered_map<string, vector<string>> map;
    for(auto x : report)
    {
        string a = x.substr(0, x.find(' '));
        string b = x.substr(x.find(' ')+1);
        map[b].push_back(a);
    }

    // 중복제거
    for(auto &x : map) 
    {
        sort(x.second.begin(), x.second.end());
        x.second.erase(unique(x.second.begin(), x.second.end()), x.second.end());
    }
    unordered_map<string, int> list;
    for(auto &x : map)
    {
        // k번 이상 신고당함 
        if(x.second.size() >= k)
        {
            for(auto &y : x.second) list[y]++;
        }
    }

//    for(auto x : map)
//    {
//        cout << x.first << ": ";
//        for(auto y : x.second) cout << y << ' ';
//        cout << endl;
//    }

    for(auto x : id_list)
    {
        answer.push_back(list[x]);
    }

    return answer;
}
