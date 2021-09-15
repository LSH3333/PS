#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end());

    auto it = numbers.begin();
    for(int i = 0; i < 10; i++)
    {
        if(*it == i)
        {
            it++;
        }
        else
        {
            answer += i;
        }
    }

    return answer;
}