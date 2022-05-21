#include <iostream>
#include <queue>
using namespace std;

int N;
int board[51][51];
int mark[51][51];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs()
{
    queue<pair<int,int>> q;
    q.push({0, 0});
    mark[0][0] = 0;

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            // 다음 위치에 기록한 값이 현재 위치 기록값과 같거나 작다면 갈 필요 없음
            if(mark[nr][nc] <= mark[r][c]) continue;
            // 검은 방 (막힌 방)
            if(board[nr][nc] == 0)
            {
                mark[nr][nc] = min(mark[nr][nc], mark[r][c]+1);
                q.push({nr, nc});
            }
            // 흰 방
            else
            {
                mark[nr][nc] = min(mark[nr][nc], mark[r][c]);
                q.push({nr, nc});
            }
        }
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string str; cin >> str;
        for(int j = 0; j < N; j++)
        {
            board[i][j] = str[j]-'0';
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            mark[i][j] = 999;
        }
    }
    bfs();

    cout << mark[N-1][N-1];
}