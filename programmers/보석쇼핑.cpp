#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    int gemsKind = 0;
    map<string,int> m;
    // 보석 종류 갯수 카운팅
    for(int i = 0; i < gems.size(); i++)
        m[gems[i]]++;
    gemsKind = m.size();
    m.clear();

    int start=0, end;
    for(int i = 0; i < gems.size(); i++)
    {
        m[gems[i]]++;
        if(m.size() == gemsKind) {end = i; break;}
    }

    answer.push_back(0);
    answer.push_back(end);
    while(end < gems.size())
    {
        cout << answer[0] << ' ' << answer[1] << endl;
        string target = gems[start];
        m[target]--;
        start++;

        if(m[target] == 0)
        {
            bool foundTarget = false;
            for(int i = end+1; i < gems.size(); i++)
            {
                m[gems[i]]++;
                if(gems[i] == target)
                {
                    end = i;
                    foundTarget = true;
                    break;
                }
            }
            if(end == gems.size()) break;
        }
        if(end-start < answer[1]-answer[0])
        {
            answer[0] = start;
            answer[1] = end;
        }
    }
    cout << endl;
    cout << answer[0] << ' ' << answer[1];
    return answer;
}

int main()
{
    vector<string> gems =
            {
                    "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"
            };

    vector<string> gems2 =
            {
                    "AA", "AB", "AC", "AA", "AC"
            };
    solution(gems2);
}