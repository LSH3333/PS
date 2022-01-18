#include <string>
#include <vector>
#include <iostream>
using namespace std;

int d[60010];

int solution(int n) {
    d[1] = 1;
    d[2] = 2;
    for(int i = 3; i <= n; i++)
        d[i] = (d[i-1] + d[i-2]) % 1000000007;


    return d[n];
}