#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
char board[101][101];
bool mark[101][101];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int r, int c, char color)
{
    mark[r][c] = true;

    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(board[nr][nc] == color && !mark[nr][nc])
        {
            dfs(nr, nc, color);
        }
    }
}

void dfs_blind(int r, int c, char color)
{
    mark[r][c] = true;

    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(mark[nr][nc]) continue;
        if(color == 'R' || color == 'G')
        {
            if(board[nr][nc] == 'R' || board[nr][nc] == 'G')
                dfs_blind(nr, nc, color);
        }
        else
        {
            if(board[nr][nc] == color)
                dfs_blind(nr, nc, color);
        }
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
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(mark[i][j]) continue;
            cnt++;
            dfs(i, j, board[i][j]);
        }
    }

    memset(mark, false, sizeof(mark));
    int cnt_blind = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(mark[i][j]) continue;
            cnt_blind++;
            dfs_blind(i, j, board[i][j]);
        }
    }

    cout << cnt << ' ' << cnt_blind;
}