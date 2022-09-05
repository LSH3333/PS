#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int a[2010][2010];
int d[2010][2010];

int main()
{
    cin >> M >> N;
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }

    for(int r = 1; r <= M; r++) d[r][1] = a[r][1];

    for(int c = 2; c <= N; c++)
    {
        for(int r = 1; r <= M; r++)
        {
            int maxVal = 0;
            if(r-1 >= 1) maxVal = max(maxVal, d[r - 1][c - 1]);
            maxVal = max(maxVal, d[r][c - 1]);
            if(r+1 <= M) maxVal = max(maxVal, d[r + 1][c-1]);

            d[r][c] = maxVal + a[r][c];
        }
    }

    int answer = 0;
    for (int r = 1; r <= M; r++)
        answer = max(answer, d[r][N - 1]);

    cout << answer;



}