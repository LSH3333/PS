#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

string Change(int n, int k)
{
    string ret;
    while(n)
    {
        ret.push_back((n%k)+'0');
        n /= k;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

bool IsItPrime(string n)
{
    long long num = stol(n);
    if(num == 1) return false;
    for(int i = 2; i <= sqrt(num); i++)
        if(num % i == 0) return false;
    return true;
}

int solution(int n, int k)
{

    stringstream ss(Change(n, k));
    string str;
    int cnt = 0;
    while(getline(ss, str, '0'))
    {
        if(!str.empty())
        {
            if(IsItPrime(str)) cnt++;
        }
    }

    return cnt;
}

int main()
{
    solution(437674, 3);
}