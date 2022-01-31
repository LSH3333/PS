#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long d[2010];

long long solution(int n) {
    long long answer = 0;

    d[1] = 1; d[2] = 2;
    for(int i = 3; i <= n; i++) d[i] = (d[i-1] + d[i-2]) % 1234567;
    answer = d[n];
    return answer;
}