#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> answer(2,0);

int binary(int n)
{
    int num[2] = {0,0};
    while(n > 0)
    {
        num[n%2]++;
        n /= 2;
    }
    answer[1] += num[0];
    return num[1];
}

vector<int> solution(string s)
{
    if(s == "1") return answer;
    int one = 0, zero = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1') one++;
        else zero++;
    }
    answer[0]++;
    answer[1] += zero;
    if(one == 1) return answer;
    while(true)
    {
        one = binary(one);
        answer[0]++;
        if(one == 1) break;
    }

    return answer;
}
