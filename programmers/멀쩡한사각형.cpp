#include <iostream>
#include <cmath>
using namespace std;

// 최대공약수
long long GCD(int a, int b)
{
    int c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w,int h) {
    long long answer = 1;

    long long gcd = GCD(w, h);

    answer = (long long)w + (long long)h - gcd;
    answer = (long long)w * (long long)h - answer;

    return answer;
}
