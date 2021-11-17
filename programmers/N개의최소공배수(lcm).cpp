#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 유클리드 호제법
int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a,b);
}

int solution(vector<int> arr)
{
    int answer = arr.front();

    for(int i = 1; i < arr.size(); i++)
    {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}
