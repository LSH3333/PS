#include <iostream>
#include <queue>
using namespace std;

int K;
int W, H;
int board[201][201];
bool mark[31][201][201];

struct Info
{
    int r;
    int c;
    int depth;
    int k;
};

int dr[] = {-1 ,0 ,1, 0, -2, -1, 1, 2, 2, 1, -1, -2};
int dc [] = {0, 1, 0, -1, 1, 2, 2, 1, -1 ,-2, -2 ,-1};

int bfs()
{
    queue<Info> q;
    q.push({0, 0, 0, K});
    mark[K][0][0] = true;

    while(!q.empty())
    {
        int r = q.front().r;
        int c = q.front().c;
        int depth = q.front().depth;
        int k = q.front().k;
        q.pop();

        if(r == H-1 && c == W-1) // 도착
        {
            return depth;
        }

        // 원숭이 이동
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if(mark[k][nr][nc] || board[nr][nc] == 1) continue;
            mark[k][nr][nc] = true;
            q.push({nr, nc, depth+1, k});
        }

        // 말 이동
        if(k > 0)
        {
            for(int i = 4; i < 12; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
                if(mark[k-1][nr][nc] || board[nr][nc] == 1) continue;
                mark[k-1][nr][nc] = true;
                q.push({nr, nc, depth+1, k-1});
            }
        }

    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> K;
    cin >> W >> H;
    for(int r = 0; r < H; r++)
    {
        for(int c = 0; c < W; c++)
        {
            cin >> board[r][c];
        }
    }

    cout << bfs();

}