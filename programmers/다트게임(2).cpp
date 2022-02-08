#include <sstream>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int solution(string dartResult)
{
    vector<string> res;
    string str = "";
    for(auto x : dartResult)
    {
        if(str.size() > 1)
            if(x != 'S' && x != 'D' && x != 'T' && x != '*' && x != '#')
            {
                res.push_back(str);
                str = "";
            }
        str.push_back(x);
    }
    res.push_back(str);

    vector<int> scores;
    vector<int> options(res.size(), 1);
    int idx = 0;
    for(auto &x : res)
    {
        // score
        string score_s = "";
        score_s += x[0];
        x.erase(0, 1);
        if(x[0] == '0') { score_s += '0'; x.erase(0, 1); }
        int score = stoi(score_s);

        // bonus
        switch(x[0])
        {
            case 'S':
                break;
            case 'D':
                score = pow(score, 2);
                break;
            case 'T':
                score = pow(score, 3);
                break;
            default: break;
        }
        x.erase(0, 1);
        scores.push_back(score);

        // option
        if(!x.empty())
        {
            if(x[0] == '*')
            {
                options[idx] *= 2;
                if(idx-1 >= 0) options[idx-1] *= 2;
            }
            else if(x[0] == '#') options[idx] *= -1;
        }
        idx++;
    }

    int answer = 0;
    for(int i = 0; i < options.size(); i++)
    {
        answer += scores[i] * options[i];
    }

    return answer;
}