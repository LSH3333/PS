#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000000
int N, M, K;
char board[1010][1010];
int mark[1010][1010][11];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct Info
{
    int r;
    int c;
    int depth;
    int chance;
};

int bfs()
{
    queue<Info> q;
    q.push({0, 0, 1,K});
    mark[0][0][K] = 1;

    while(!q.empty())
    {
        int r = q.front().r, c = q.front().c;
        int depth = q.front().depth;
        int chance = q.front().chance;
        q.pop();

        if(r == N-1 && c == M-1)
        {
            return depth;
        }

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            // 다음이 뚫린 길 
            if(board[nr][nc] == '0' && mark[nr][nc][chance] > mark[r][c][chance]+1)
            {
                q.push({nr, nc, depth + 1, chance});
                mark[nr][nc][chance] = depth+1;
            }
            // 다음이 막힌 길 && 아직 벽을 뚫을 기회 남아 있음 
            else if (board[nr][nc] == '1' && chance >= 1)
            {
                if(mark[nr][nc][chance-1] > mark[r][c][chance]+1)
                {
                    q.push({nr, nc, depth+1, chance-1});
                    mark[nr][nc][chance-1] = depth+1;
                }
            }
        }
    }
    return -1;
}

void Init()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            for(int k = 0; k <= K; k++)
            {
                mark[i][j][k] = INF;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    Init();


    cout << bfs();

}