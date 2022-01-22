#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(int n)
{
    string answer = "";

    while(n > 0)
    {
        int left = n % 3;
        n /= 3;

        if(left == 0)
        {
            n--;
            left = 4;
        }
        answer.push_back(left+'0');
    }
    reverse(answer.begin(), answer.end());
    return answer;
}