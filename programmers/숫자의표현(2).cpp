#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        int sum = i;
        for(int j = i + 1; j <= n; j++)
        {
            sum += j;
            if(sum > n) break;
            if(sum == n) ans++;
        }
    }
    return ans+1;
}
