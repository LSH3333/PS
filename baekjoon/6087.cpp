#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 100000000

int W, H;
char board[110][110];
int mark[110][110]; // 해당 위치까지 레이저 연결했을때 사용한 거울 갯수
vector<pair<int,int>> goal;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct Info
{
    int r;
    int c;
    int mirror;
    int prev_dir;
};

int bfs()
{
    int startR = goal.front().first, startC = goal.front().second;
    int goalR = goal.back().first, goalC = goal.back().second;
    queue<Info> q;
    q.push({startR, startC, 0, -1});
    mark[startR][startC] = 0;

    int ret = INF;

    while(!q.empty())
    {
        int r = q.front().r;
        int c = q.front().c;
        int mirror = q.front().mirror;
        int prev_dir = q.front().prev_dir;
        q.pop();

//        cout << "(" << r << ',' << c << ")" << endl;
//        cout << "mirror: " << mirror << endl;
//        cout << endl;

        if(r == goalR && c == goalC)
        {
            ret = min(ret, mirror);
        }

        for(int dir = 0; dir < 4; dir++)
        {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if(nr < 0 || nr >= H || nc < 0 || nc >= W || board[nr][nc] == '*') continue;
            if(prev_dir != -1 && dir == ((prev_dir + 2) % 4)) continue; // 반대 방향으로는 가지 않음

            if(prev_dir == -1)
            {
                mark[nr][nc] = mirror;
                q.push({nr, nc, mirror, dir});
            }
            else if(dir == prev_dir)
            {
                if(mark[nr][nc] > mirror)
                {
                    mark[nr][nc] = mirror;
                    q.push({nr, nc, mirror, dir});
                }
            }
            else if(dir != prev_dir)
            {
                if(mark[nr][nc] > mirror)
                {
                    mark[nr][nc] = mirror + 1;
                    q.push({nr, nc, mirror+1, dir});
                }
            }
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> W >> H;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cin >> board[i][j];
            mark[i][j] = INF;
            if(board[i][j] == 'C')
            {
                board[i][j] = '.';
                goal.push_back({i,j});
            }
        }
    }

    cout << bfs();
}