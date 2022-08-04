#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int dr[] = {-1,0,1,0};
int dc[] = {0, 1, 0, -1};
int board[510][510];
int d[510][510];
int answer = 1;

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

void dfs(int r, int c)
{
    if(d[r][c] != 1) return;

    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(board[nr][nc] <= board[r][c]) continue;
        if(d[nr][nc] >= d[r][c]+1) continue;
        d[nr][nc] = d[r][c]+1;
        answer = max(answer, d[nr][nc]);
        dfs(nr,nc);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            d[i][j] = 1;
        }
    }


    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
        {
            if(d[r][c] > 1) continue;
            dfs(r,c);
        }
    }

    cout << answer;
}
