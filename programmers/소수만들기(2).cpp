#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


// 가능한 모든 수들이 들어감
vector<int> ans;

bool isPrime(int n)
{
    if(n < 2) return false;

    for(int i = 2; i < n; i++)
        if(n % i == 0)
            return false;


    return true;
}

int solution(string numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end());

    do {
        string str = "";
        for(int i = 0; i < numbers.size(); i++)
        {
            str.push_back(numbers[i]);
            ans.push_back(stoi(str));
        }

    } while(next_permutation(numbers.begin(), numbers.end()));

    // 중복 제거
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for(int i = 0; i < ans.size(); i++)
    {
        if(isPrime(ans[i]))
            answer++;
    }

    return answer;
}