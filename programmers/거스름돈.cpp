#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MOD 1000000007
using namespace std;

int d[100001];


int solution(int n, vector<int> money) {
    int answer = 0;

    d[0] = 1;
    for(int i = 0; i < money.size(); i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j-money[i] < 0) continue;
            d[j] += d[j-money[i]] % MOD;
        }
    }

    return d[n];
}

int main()
{
    vector<int> money = {1,2,5};
    solution(5, money);
}