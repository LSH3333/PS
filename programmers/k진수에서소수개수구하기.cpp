#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

string Change(int n, int k)
{
    string str;
    while(n > 0)
    {
        str.push_back((n%k)+'0');
        n /= k;
    }
    reverse(str.begin(), str.end());
    return str;
}

bool IsItPrime(string s)
{
    if(s == "1") return false;
    auto num = stol(s);
    long long until = sqrt(num);
    for(long long i = 2; i <= until; i++)
    {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    // n을 k진수로 변환
    string s = Change(n, k);
    stringstream ss(s);
    vector<string> v;
    string str;
    while(getline(ss, str, '0'))
    {
        if(!str.empty())
        {
            v.push_back(str);
        }
    }

    for(auto x : v)
    {
        if(IsItPrime(x)) answer++;
    }

    return answer;
}