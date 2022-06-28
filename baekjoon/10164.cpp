#include <iostream>
using namespace std;

int d[20][20];

int main()
{
    int N, M, K;
    int a, b;
    cin >> N >> M >> K;

    if(K != 0)
    {
        int R, C;
        int cnt = 1;
        for(int r = 0; r < N; r++)
        {
            for(int c = 0; c < M; c++)
            {
                if(cnt++ == K) { R = r; C = c; break;}
            }
        }

        // ~ R,C
        for(int r = 0; r <= R; r++) d[r][0] = 1;
        for(int c = 0; c <= C; c++) d[0][c] = 1;
        for(int r = 1; r <= R; r++)
        {
            for(int c = 1; c <= C; c++)
            {
                d[r][c] = d[r-1][c] + d[r][c-1];
            }
        }
        a = d[R][C];

        // R,C ~
        for(int r = R; r < N; r++) d[r][C] = 1;
        for(int c = C; c < M; c++) d[R][c] = 1;
        for(int r = R+1; r < N; r++)
        {
            for(int c = C+1; c < M; c++)
            {
                d[r][c] = d[r-1][c] + d[r][c-1];
            }
        }
        b = d[N-1][M-1];

        cout << a*b;
    }
    else
    {
        for(int r = 0; r < N; r++) d[r][0] = 1;
        for(int c = 0; c < M; c++) d[0][c] = 1;
        for(int r = 1; r < N; r++)
        {
            for(int c = 1; c < M; c++)
            {
                d[r][c] = d[r-1][c] + d[r][c-1];
            }
        }
        cout << d[N-1][M-1];
    }

}