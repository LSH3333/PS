#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char number[18] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                   'A', 'B', 'C', 'D', 'E', 'F'};

string CalculateNotation(int num, int n)
{
    if(num == 0) return "0";

    string temp = "";
    while(num)
    {
        temp += number[num % n];
        num /= n;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string nums = "";
    for(int i = 0; nums.size() <= m*t; i++)
    {
        nums += CalculateNotation(i, n);
    }

    int cnt = 0;
    for(int i = p-1; i < nums.size(); i += m)
    {
        if(cnt >= t) break;

        cnt++;
        answer.push_back(nums[i]);
    }

    return answer;
}
