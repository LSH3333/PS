#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 길이 우선 정렬, 같다면 사전순 정렬
bool cmp(const string &a, const string &b)
{
    if(a.size() == b.size())
    {
        return a < b;
    }
    return a.size() < b.size();
}

void Reverse(vector<string> &words)
{
    for(int i = 0; i < words.size(); i++)
        reverse(words[i].begin(), words[i].end());
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    // 뒤집음
    vector<string> opposite = words;
    Reverse(opposite);

    sort(words.begin(), words.end(), cmp);
    sort(opposite.begin(), opposite.end(), cmp);

    for(int i = 0; i < queries.size(); i++)
    {
        string zz = queries[i];
        string aa = queries[i];
        int up,low;

        for(int j = 0; j < queries[i].size(); j++)
        {
            if(queries[i][j] == '?')
            {
                zz[j] = 'z';
                aa[j] = 'a';
            }
        }

        // 접미 ?, words 탐색
        if(queries[i][0] != '?')
        {
            up =  upper_bound(words.begin(), words.end(), zz, cmp) - words.begin();
            low = lower_bound(words.begin(), words.end(), aa, cmp) - words.begin();
        }
        else // 접두 ?, opposite 탐색
        {
            reverse(aa.begin(), aa.end());
            reverse(zz.begin(), zz.end());

            up = upper_bound(opposite.begin(), opposite.end(), zz, cmp) - opposite.begin();
            low = lower_bound(opposite.begin(), opposite.end(), aa, cmp) - opposite.begin();
        }
        answer.push_back(up-low);
    }

    return answer;
}

int main()
{
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    solution(words, queries);
}