#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    unordered_map<string, vector<string>> reports;
    unordered_map<string, int> counts;
    for(auto x : report)
    {
        string a = x.substr(0, x.find(' '));
        string b = x.substr(x.find(' ')+1);
        reports[a].push_back(b);
    }

    // unique erase
    for(auto &x : reports)
    {
        sort(x.second.begin(), x.second.end());
        x.second.erase(unique(x.second.begin(), x.second.end()), x.second.end());
    }

    // count
    for(auto &x : reports)
    {
        for(auto &y : x.second) counts[y]++;
    }

    vector<int> answer;
    for(auto &x : id_list)
    {
        int cnt = 0;
        for(auto &y : reports[x])
        {
            if(counts[y] >= k) cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}

int main()
{
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};

//    vector<string> id_list = {"con", "ryan"};
//    vector<string> report = {"ryan con", "ryan con", "ryan con", "ryan con"};
    solution(id_list, report, 2);
}