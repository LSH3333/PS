#include <iostream>
using namespace std;

int N;
int dr[] = {-1,0,1,0};
int dc[] = {0, 1, 0, -1};
int board[510][510];
int d[510][510];
int answer;

int dfs(int r, int c)
{
    if(d[r][c] > 0) return d[r][c];

    d[r][c] = 1;
    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(board[nr][nc] <= board[r][c]) continue;
        d[r][c] = max(d[r][c], dfs(nr, nc)+1);
    }
    return d[r][c];
}

void Print()
{
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
        {
            cout << d[r][c] << ' ';
        }cout<<endl;
    }cout<<endl;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
        {
            answer = max(dfs(r,c),answer);
        }
    }

    cout << answer;

}