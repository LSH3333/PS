#include <iostream>
using namespace std;

int N, M;
long long board[1030][1030];

void CalSum()
{
    // 행 별로 더해감
    for(int r = 1; r <= N; r++)
    {
        for(int c = 2; c <= N; c++)
        {
            board[r][c] += board[r][c - 1];
        }
    }
    // 열 별로 더해감
    for(int c = 1; c <= N; c++)
    {
        for(int r = 2; r <= N; r++)
        {
            board[r][c] += board[r-1][c];
        }
    }
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }

    CalSum();

    for(int i = 0; i < M; i++)
    {
        int r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2;
        // [r2][c2] 정사각형에서 포함되지 않는 직사각형 뺌 
        cout << board[r2][c2] - (board[r1-1][c2] + (board[r2][c1-1] - board[r1-1][c1-1])) << '\n';
    }
}