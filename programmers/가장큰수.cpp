#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(const string &a, const string &b)
{
    string tempA = a+b;
    string tempB = b+a;

    return tempA > tempB;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> nums;
    for(int i = 0; i < numbers.size(); i++)
        nums.push_back(to_string(numbers[i]));

    sort(nums.begin(), nums.end(), cmp);

    for(auto x : nums)
        answer += x;

    if(answer[0] == '0') return "0";

    return answer;
}
