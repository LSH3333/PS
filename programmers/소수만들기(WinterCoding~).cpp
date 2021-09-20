#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool IsItPrime(int num)
{
    if(num <= 2) return true;

    for(int i = 2; i < num; i++)
    {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    vector<bool> d(nums.size(), false);
    d[0] = true; d[1] = true; d[2] = true;

    do {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(d[i]) sum += nums[i];
        }

        if(IsItPrime(sum)) answer++;
    }while(prev_permutation(d.begin(), d.end()));

    return answer;
}
