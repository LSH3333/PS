#include <iostream>
#include <queue>
using namespace std;

int R, C;
char board[51][51];
int Dist, r1, c1, r2, c2;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs(int _r, int _c)
{
    vector<vector<bool>> mark(R, vector<bool>(C, false));
    queue<pair<pair<int,int>,int>> q;
    mark[_r][_c] = true;
    q.push({{_r,_c}, 0});

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        if(depth > Dist)
        {
            Dist = depth;
            r1 = _r; c1 = _c;
            r2 = r; c2 = c;
        }

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(mark[nr][nc] || board[nr][nc] == 'W') continue;
            mark[nr][nc] = true;
            q.push({{nr,nc}, depth+1});
        }
    }

}

int main()
{
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        string str; cin >> str;
        for(int j = 0; j < C; j++)
        {
            board[i][j] = str[j];
        }
    }

    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            if(board[r][c] == 'W') continue;
            bfs(r, c);
        }
    }
    cout << Dist;
}