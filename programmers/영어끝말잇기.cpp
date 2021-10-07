#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    map<string, bool> m;
    int num = 0, round = 0;
    char last;
    for(int i = 0; i < words.size(); i++)
    {
        string word = words[i];

        // 중복 단어
        if(m[word])
        {
            answer.push_back(num+1);
            answer.push_back(round+1);
            break;
        }

        // 이전 마지막 글자와 다름
        if(i > 0 && last != word.front())
        {
            answer.push_back(num+1);
            answer.push_back(round+1);
            break;
        }

        m[word] = true;
        last = word.back();
        num = (num + 1) % n;
        // 라운드 증가
        if(num == 0) round++;
    }

    if(answer.empty()) return {0,0};

    return answer;
}
