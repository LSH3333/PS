#include <iostream>
using namespace std;

int a[1050][1050];
int d[1050][1050];
int N, M;

void CalD()
{
    for(int r = 1; r <= N; r++)
    {
        for(int c = 1; c <= M; c++)
        {
            d[r][c] = d[r-1][c] + d[r][c-1] - d[r-1][c-1] + a[r][c];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> a[i][j];
        }
    }

    CalD();

    int K; cin >> K;
    while(K--)
    {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        int answer = d[r2][c2] - d[r2][c1-1] - d[r1-1][c2] + d[r1-1][c1-1];
        cout << answer << '\n';
    }

}