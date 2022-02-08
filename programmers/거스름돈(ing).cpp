#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 100000007
using namespace std;

long long d[101][100001];

int solution(int n, vector<int> money) {
    int answer = 0;

    for(int c = 1; c <= n; c++)
    {
        long long cnt = 0;
        for(int r = 0; r < money.size(); r++)
        {
            if(c - money[r] <= 0)
            {
                d[r][c] = 1 + cnt;
                cnt += d[r][c];
                continue;
            }
            d[r][c] += d[r][c - money[r]] + cnt;
            cnt += d[r][c];
        }
    }

    for(int r = 0; r < money.size(); r++)
    {
        for(int c = 1; c <= n; c++)
        {
            cout << d[r][c] << ' ';
        } cout << endl;
    }

    return answer;
}

int main()
{
    vector<int> money = {1,2,5};
    solution(5, money);
}