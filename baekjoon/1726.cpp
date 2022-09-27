#include <iostream>
#include <queue>
using namespace std;

#define RIGHT 1
#define LEFT 2
#define DOWN 3
#define UP 4

int R, C;
int board[110][110];
bool visited[110][110][5];

int dr[] = {0, 0, 0, 1, -1};
int dc[] = {0, 1, -1, 0, 0};

struct Info
{
    int r;
    int c;
    int dir;
};

Info startInfo, goalInfo;

int GetLeft(int dir)
{
    if(dir == RIGHT) return UP;
    if(dir == LEFT) return DOWN;
    if(dir == DOWN) return RIGHT;
    if(dir == UP) return LEFT;
}
int GetRight(int dir)
{
    if(dir == RIGHT) return DOWN;
    if(dir == LEFT) return UP;
    if(dir == DOWN) return LEFT;
    if(dir == UP) return RIGHT;
}

int bfs()
{
    queue<pair<Info, int>> q;
    visited[startInfo.r][startInfo.c][startInfo.dir] = true;
    q.push({startInfo, 0});

    while(!q.empty())
    {
        Info cur = q.front().first;
        int depth = q.front().second;
        q.pop();



        if(cur.r == goalInfo.r && cur.c == goalInfo.c && cur.dir == goalInfo.dir)
        {
            return depth;
        }

        // Go k
        for(int i = 1; i <= 3; i++)
        {
            int nr = cur.r + (dr[cur.dir] * i);
            int nc = cur.c + (dc[cur.dir] * i);
            if(nr < 1 || nr > R || nc < 1 || nc > C) break;
            if(board[nr][nc] == 1) break;
            if(visited[nr][nc][cur.dir]) continue;
            visited[nr][nc][cur.dir] = true;
            q.push({{nr,nc,cur.dir}, depth+1});
        }

        // dir
        int left = GetLeft(cur.dir);
        if(!visited[cur.r][cur.c][left])
        {
            visited[cur.r][cur.c][left] = true;
            q.push({{cur.r, cur.c, left}, depth+1});
        }
        int right = GetRight(cur.dir);
        if(!visited[cur.r][cur.c][right])
        {
            visited[cur.r][cur.c][right] = true;
            q.push({{cur.r, cur.c, right}, depth+1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            cin >> board[i][j];
        }
    }

    cin >> startInfo.r >> startInfo.c >> startInfo.dir;
    cin >> goalInfo.r >> goalInfo.c >> goalInfo.dir;

    cout << bfs();

}