#include <iostream>
using namespace std;

#define MOD 10007
int d[1001][1001];

int main()
{
    // 파스칼의 삼각형
    d[0][0] = 1;
    for(int i = 1; i <= 1000; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            int a = 0, b = 0;
            if(j-1 >= 0) a = d[i-1][j-1];
            b = d[i-1][j];
            d[i][j] = (a + b) % MOD;
        }
    }

    int N, K; cin >> N >> K;
    cout << d[N][K];

}