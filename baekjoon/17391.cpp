#include <iostream>
using namespace std;

#define INF 100000000
int N, M;
int a[310][310];
int d[310][310];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> a[i][j];
            d[i][j] = INF;
        }
    }

    d[0][0] = 0;
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            int len = a[r][c];

            for(int rr = r+1; rr < r+1+len; rr++)
            {
                d[rr][c] = min(d[rr][c], d[r][c]+1);
            }
            for(int cc = c+1; cc < c+1+len; cc++)
            {
                d[r][cc] = min(d[r][cc], d[r][c]+1);
            }
        }
    }

    cout << d[N-1][M-1];
}