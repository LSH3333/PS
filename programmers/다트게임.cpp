#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;

    // 문자열 나누기
    vector<string> v;
    // under flow 방지
    v.push_back("0");
    string temp = "";
    temp += dartResult[0];
    for(int i = 1; i < dartResult.size(); i++)
    {
        if((dartResult[i] >= '0' && dartResult[i] <= '9') && temp.size() > 1)
        {
            v.push_back(temp);
            temp = "";
        }
        temp += dartResult[i];
    }
    v.push_back(temp);


    vector<int> mul(v.size(), 1);
    for(int i = 1; i < v.size(); i++)
    {
        if(v[i].back() == '*')
        {
            mul[i] *= 2;
            mul[i-1] *= 2;
        }
        else if(v[i].back() == '#')
        {
            mul[i] *= -1;
        }
    }

    for(int i = 1; i < mul.size(); i++)
    {
        string token = v[i];
        int num, poweridx, power;

        // 세자리
        if(token[1] >= '0' && token[1] <= '9')
        {
            string temp = "";
            temp += token[0];
            temp += token[1];
            num = stoi(temp);
            poweridx = 2;
        }
        else // 두자리
        {
            num = token[0] - '0';
            poweridx = 1;
        }

        if(token[poweridx] == 'D') power = 2;
        else if(token[poweridx] == 'S') power = 1;
        else power = 3;

        answer += pow(num, power) * mul[i];
    }

    return answer;
}
