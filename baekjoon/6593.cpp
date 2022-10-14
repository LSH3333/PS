#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Info
{
    int l;
    int r;
    int c;
    int depth;
};

int L, R, C;
char board[35][35][35];
bool visited[35][35][35];
Info startPos, endPos;

int dl[] = {0, 0, 0, 0, -1, 1};
int dr[] = {-1, 0, 1, 0, 0, 0};
int dc[] = {0, 1, 0, -1, 0, 0};


int bfs()
{
    queue<Info> q;
    visited[startPos.l][startPos.r][startPos.c] = true;
    q.push(startPos);

    while(!q.empty())
    {
        Info cur = q.front();
        q.pop();

        if(cur.l == endPos.l && cur.r == endPos.r && cur.c == endPos.c)
        {
            return cur.depth;
        }

        for(int i = 0; i < 6; i++)
        {
            int nl = cur.l + dl[i];
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if(nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(visited[nl][nr][nc] || board[nl][nr][nc] == '#') continue;
            visited[nl][nr][nc] = true;
            q.push({nl, nr, nc, cur.depth+1});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(true)
    {
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) break;

        for(int l = 0; l < L; l++)
        {
            for(int r = 0; r < R; r++)
            {
                string str; cin >> str;
                for(int c = 0; c < C; c++)
                {
                    board[l][r][c] = NULL;
                    visited[l][r][c] = false;

                    char tmp = str[c];
                    board[l][r][c] = tmp;
                    if(board[l][r][c] == 'S')
                    {
                        board[l][r][c] = '.';
                        startPos = {l, r, c, 0};
                    }
                    else if(board[l][r][c] == 'E')
                    {
                        board[l][r][c] = '.';
                        endPos = {l, r, c, 0};
                    }
                }
            }
        }

        int res = bfs();
        if(res == -1)
        {
            cout << "Trapped!\n";
        }
        else
        {
            cout << "Escaped in " << res << " minute(s).\n";
        }
    }


}