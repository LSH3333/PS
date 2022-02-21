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
    long long a, b;

    lcm /= gcd;
    for(int i = 1; i * i <= lcm; i++)
    {
        if(lcm % i != 0) continue;
        long long a_tmp = i;
        long long b_tmp = lcm / i;
//        cout << a_tmp << ' ' << b_tmp << endl;
        // 최대공약수가 1
        if(GCD(a_tmp, b_tmp) == 1)
        {
            a = a_tmp;
            b = b_tmp;
        }
    }

    cout << a*gcd << ' ' << b*gcd;
}