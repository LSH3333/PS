#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

vector<int> solution(vector<string> gems)
{
    unordered_map<string, int> m;
    for(auto x : gems) m[x]++;
    int total = (int)m.size();
    m.clear();

    vector<int> answer = {200000, 200000};
    int ansLen = 200000;
    int start = 0, end = 0;
    for(end = 0; end < gems.size(); end++)
    {
        string endGem = gems[end];
        m[endGem]++;

        // 새롭게 추가된 보석에 의해 시작부분에서 제외해도 될 보석들 탐색
        for(int i = start; i < end; i++)
        {
            if(m[gems[i]] > 1)
            {
                m[gems[i]]--;
                if(m[gems[i]] == 0) m.erase(gems[i]);
                start = i+1;
            }
            else break;
        }
//        cout << start << ' ' << end << ' ' << m.size() << ' ' << answer[0] << ' ' << answer[1] << ' ' << ansLen << endl;
        if(m.size() >= total && end-start+1 < ansLen)
        {
            answer[0] = start; answer[1] = end;
            ansLen = answer[1] - answer[0] + 1;
        }
    }

    answer[0]++; answer[1]++;
//    cout << answer[0] << ' ' << answer[1];
    return answer;
}

int main()
{
    vector<string> gems =
            {
                    "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"
            };
    gems =
            {
                "DIA", "EM", "EM", "RUB", "DIA"
            };
    solution(gems);
}



