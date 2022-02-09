#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MOD 1000000007
using namespace std;

int d[101][100001];

int solution(int n, vector<int> money) {
    int answer = 0;
//    sort(money.begin(), money.end());

    for(int i = 0; i < money.size(); i++)
        d[i][money[i]] = 1;

    for(int i = 0; i < money.size(); i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int coin = money[i];
            if(i == 0)
            {
                if(j-coin < 1) continue;
                d[i][j] += d[i][j-coin] % MOD;
            }
            else
            {
                if(j-coin >= 1)
                {
                    d[i][j] += d[i-1][j] % MOD;
                    d[i][j] += d[i][j-coin] % MOD;
                }
                else d[i][j] += d[i-1][j] % MOD;
            }
        }
    }
//
//    for(int i = 0; i < money.size(); i++)
//    {
//        for(int j = 1; j <= n; j++)
//        {
//            cout << d[i][j] << ' ';
//        } cout << endl;
//    }

    answer = d[money.size()-1][n];
    return answer;
}

int main()
{
    vector<int> money = {1,2,5};
    solution(5, money);
}