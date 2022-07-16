#include <iostream>
#include <vector>
using namespace std;

#define HORZ 0
#define VERT 1
#define DIAG 2

int N;
int house[20][20];
int d[3][20][20];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> house[i][j];
        }
    }

    d[HORZ][1][2] = 1;
    for(int r = 1; r <= N; r++)
    {
        for(int c = 2; c <= N; c++)
        {
            if(r == 1 && c == 2) continue;
            if(house[r][c] != 1) d[HORZ][r][c] = d[HORZ][r][c-1] + d[DIAG][r][c-1];
            if(house[r][c] != 1) d[VERT][r][c] = d[VERT][r-1][c] + d[DIAG][r-1][c];
            if(house[r-1][c] != 1 && house[r][c] != 1 && house[r][c-1] != 1)
                d[DIAG][r][c] = d[HORZ][r-1][c-1] + d[VERT][r-1][c-1] + d[DIAG][r-1][c-1];
        }
    }

    cout << d[HORZ][N][N] + d[VERT][N][N] + d[DIAG][N][N];

}