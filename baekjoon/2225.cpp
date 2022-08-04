#include <iostream>
using namespace std;
#define MOD 1000000000
// i개로 j를 만드는 경우의 수
int d[210][210];

int main()
{
    int N, K; cin >> N >> K;
    for(int i = 0; i <= N; i++) d[1][i] = 1;

    for(int i = 2; i <= K; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            int sum = 0;

            for(int k = j; k >= 0; k--)
            {
                sum = (sum + d[i-1][k]) % MOD;
            }
            d[i][j] = sum;
        }
    }

    cout << d[K][N];
}