#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";

    int need = number.size() - k;
    int maxIdx = -1;
    for(int i = 0; i < need; i++)
    {
        char maxNum = '0';
        for(int j = maxIdx+1; j <= i + k; j++)
        {
            if(number[j] > maxNum)
            {
                maxIdx = j;
                maxNum = number[j];
            }
        }
        answer.push_back(maxNum);
    }

    return answer;
}