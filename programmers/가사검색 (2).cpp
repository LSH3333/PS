#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b)
{
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

void Reverse(vector<string> &wordsReversed)
{
    for(auto &x : wordsReversed)
    {
        reverse(x.begin(), x.end());
    }
}

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;
    vector<string> wordsReversed = words;

    Reverse(wordsReversed);
    sort(words.begin(), words.end(), cmp);
    sort(wordsReversed.begin(), wordsReversed.end(), cmp);

//
//    for(auto x : words) cout << x << ' '; cout << endl;
//    for(auto x : wordsReversed) cout << x << ' '; cout << endl;

    for(auto query : queries)
    {
        // 접두 true, 접미 false
        bool pre = false;
        if(query.front() == '?') pre = true;

        string aa, zz;
        for(int i = 0; i < query.size(); i++)
        {
            if(query[i] == '?')
            {
                aa += 'a';
                zz += 'z';
            }
            else
            {
                aa += query[i];
                zz += query[i];
            }
        }

        // 접두
        if(pre)
        {
            reverse(aa.begin(), aa.end());
            reverse(zz.begin(), zz.end());
            int beginIdx = lower_bound(wordsReversed.begin(), wordsReversed.end(), aa, cmp) - wordsReversed.begin();
            int endIdx = upper_bound(wordsReversed.begin(), wordsReversed.end(), zz, cmp) - wordsReversed.begin();
            answer.push_back(endIdx-beginIdx);
        }
        else
        {
            int beginIdx = lower_bound(words.begin(), words.end(), aa, cmp) - words.begin();
            int endIdx = upper_bound(words.begin(), words.end(), zz, cmp) - words.begin();
            answer.push_back(endIdx-beginIdx);
        }
    }

//    for(auto x : answer) cout << x << ' ';

    return answer;
}

int main()
{
    vector<string> words =
            {
                    "frodo", "front", "frost", "frozen", "frame", "kakao"
            };
    vector<string> queries =
            {
                    "fro??", "????o", "fr???", "fro???", "pro?"
            };
    solution(words, queries);
}