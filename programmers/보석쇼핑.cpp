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

    int start=0, end=0;
    for(int i = 0; i < gems.size(); i++)
    {
        m[gems[i]]++;
        if(m.size() == gemsKind) {end = i; break;}
    }

    answer.push_back(0);
    answer.push_back(end);
    int sub = answer[1] - answer[0];
    while(end < gems.size())
    {
        string target = gems[start];
        start++;
        m[target]--;

        // 타깃 보석의 남은 수가 0개가 됐다면,
        // end 증가시켜 뒤에 해당 보석이 있는지 탐색
        if(m[target] == 0)
        {
            for(end++; end < gems.size(); end++)
            {
                m[gems[end]]++;
                if(gems[end] == target) break;
            }
            if(end == gems.size()) break; // gems 배열 끝에 도달함

        }
        if(sub > end - start)
        {
            answer[0] = start;
            answer[1] = end;
            sub = end - start;
        }
    }

    answer[0]++; answer[1]++;
    return answer;
}
