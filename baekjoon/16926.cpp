#include <iostream>
using namespace std;

int N, M, R;
int board[301][301];


void Spin(int _r, int _c, int n, int m)
{
    int temp = board[_r][_c];
    int r = _r, c = _c;

    for(; c < _c + m - 1; c++)
    {
        board[r][c] = board[r][c+1];
    }
    for(c = _c + m - 1; r < _r + n - 1; r++)
    {
        board[r][c] = board[r+1][c];
    }
    for(r = _r + n - 1; c > _c; c--)
    {
        board[r][c] = board[r][c-1];
    }
    for(c = _c; r > _r+1; r--)
    {
        board[r][c] = board[r-1][c];
    }
    board[_r+1][c] = temp;
}

void Print()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << board[i][j] << ' ';
        } cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> R;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < R; i++)
    {
        int _n = N, _m = M;
        int _r = 0, _c = 0;
        while(_n > 0 && _m > 0)
        {
            Spin(_r, _c, _n, _m);
            _n -= 2; _m -= 2;
            _r += 1; _c += 1;
        }
    }

    Print();
}