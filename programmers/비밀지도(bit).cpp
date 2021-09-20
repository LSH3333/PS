#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    for(int i = 0; i < n; i++)
    {
        arr1[i] = arr1[i] | arr2[i]; // 두 십진수 비트 or 연산
        string ans = "";

        for(int j = 0; j < n; j++) // n자리
        {
            if(arr1[i] % 2 == 0) ans += " ";
            else ans += "#";
            arr1[i] = arr1[i] >> 1; // 1 우측 쉬프트
        }
        reverse(ans.begin(), ans.end());
        answer.push_back(ans);
    }

    return answer;
}