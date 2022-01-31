#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long d[2010];

long long pibo(int i)
{
    if(i <= 2) return i;
    if(d[i] > 0) return d[i];
    return d[i] = (pibo(i-1) + pibo(i-2)) % 1234567;
}

long long solution(int n) {
    long long answer = 0;
    return pibo(n);
}