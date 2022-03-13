#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long GCD(long long a, long long b)
{
    if(b == 0) return a;
    return GCD(b, a%b);
}

int main()
{
    // 최대공약수, 최소공배수
    long long gcd, lcm;
    cin >> gcd >> lcm;

    long long m = lcm / gcd;
    long long a, b;
    for(int i = 1; i * i <= m; i++)
    {
        // 약수 중에서
        if(m % i != 0) continue;
        if(GCD(i, m/i) == 1) // 서로소인가
        {
            a = i; b = m/i;
        }
    }
    // 각 a,b에 최대공약수를 곱한 값이 답 
    cout << a*gcd << ' ' << b*gcd;
}