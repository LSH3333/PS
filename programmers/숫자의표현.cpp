#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int d[100010] = {0,};

    for(int i = 1; i <= n; i++)
    {
        int sum = i;
        d[sum]++;
        for(int j = i+1; j <= n; j++)
        {
            if(sum >= n) break;
            sum += j;
            d[sum]++;
        }
    }

    return d[n];
}
