#include <iostream>
using namespace std;

#define MAX 10000

int N, M;
int A[110];
int C[110];
int d[110][10010];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    for(int i = 1; i <= N; i++)
    {
        cin >> C[i];
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= MAX; j++)
        {
            if(j - C[i] >= 0)
            {
                int put = d[i-1][j-C[i]] + A[i];
                d[i][j] = max(d[i-1][j], put);
            }
            else
            {
                d[i][j] = d[i-1][j];
            }
        }
    }

    for(int i = 0; i <= MAX; i++)
    {
        if(d[N][i] >= M)
        {
            cout << i;
            break;
        }
    }
    
}