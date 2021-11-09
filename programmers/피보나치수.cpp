#include <iostream>
#include <algorithm>
using namespace std;

long long d[1000001];

long long dp(int n)
{
    if(n <= 1) return n;
    if(d[n] > 0) return d[n];

    d[n] = (dp(n-1) % 1234567) + (dp(n-2) % 1234567);
    return d[n] % 1234567;

}

int solution(int n)
{
    d[0] = 0;
    d[1] = 1;

    return dp(n);
}
