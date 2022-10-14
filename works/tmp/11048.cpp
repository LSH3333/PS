#include <iostream>
using namespace std;

int a[1010][1010];
int d[2][1010][1010];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            d[0][i][j] = max(d[0][i][j-1]+a[i][j], d[1][i][j-1]+a[i][j]);
            d[1][i][j] = max(d[0][i-1][j]+a[i][j], d[1][i-1][j]+a[i][j]);
        }
    }

    cout << max(d[0][N][M], d[1][N][M]);
}