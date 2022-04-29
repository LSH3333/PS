#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

int solution(string dartResult)
{
    vector<int> num(3);
    vector<int> bonus(3);
    vector<int> option(3);

    int idx = -1;
    for(int i = 0; i < dartResult.size(); i++)
    {
        char c = dartResult[i];
        // 숫자
        if(c >= '0' && c <= '9')
        {
            idx++;
            if(dartResult[i+1] == '0')
            { num[idx] = 10; i++; }
            else
                num[idx] = c-'0';
        }
        else if(c == 'S') bonus[idx] = 1;
        else if(c == 'D') bonus[idx] = 2;
        else if(c == 'T') bonus[idx] = 3;
        else if(c == '*') option[idx] = 2;
        else if(c == '#') option[idx] = -1;
    }

//    for(auto x : num) cout << x << ' '; cout << endl;
//    for(auto x : bonus) cout << x << ' '; cout << endl;
//    for(auto x : option) cout << x << ' '; cout << endl;

    int ans[3] = {0,};
    for(int i = 0; i < 3; i++)
    {
        ans[i] += (int)pow(num[i], bonus[i]);
        if(option[i] == 2)
        {
            ans[i] *= 2;
            if(i-1 >= 0) ans[i-1] *= 2;
        }
        else if(option[i] == -1)
        {
            ans[i] *= -1;
        }
    }

    int answer = ans[0] + ans[1] + ans[2];
    return answer;
}

int main()
{
    string dartResult = "1D2S3T*";
    solution(dartResult);
}