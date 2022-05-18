#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[101][101];
int mark[101][101];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void Print()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            printf("%2d ", mark[i][j]);
        }cout<< endl;
    }cout<<endl;
}

void bfs()
{
    // r, c, 부순 벽의 수
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0}, 0});
    mark[0][0] = 0;

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int wall = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            // 다음 지점이 벽이고, 더 적게 벽을 부수고 갈수 있다면 q에 push
            if(board[nr][nc] == 1 && mark[nr][nc] > wall+1)
            {
                mark[nr][nc] = wall+1;
                q.push({{nr,nc}, wall+1});
            }
            // 다음 지점이 빈 공간
            else if(board[nr][nc] == 0 && mark[nr][nc] > wall)
            {
                mark[nr][nc] = wall;
                q.push({{nr,nc}, wall});
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> M >> N;
    for(int i = 0; i < N; i++)
    {
        string str; cin >> str;
        for(int j = 0; j < M; j++)
        {
            board[i][j] = str[j]-'0';
            mark[i][j] = 10000;
        }
    }

    bfs();

    cout << mark[N-1][M-1];
}