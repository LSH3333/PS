#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[110][110];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs()
{
    queue<pair<int,int>> q;
    q.push({0,0});

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c+ dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(board[nr][nc] != 0) continue;
            board[nr][nc] = 2; // 외부 표시
            q.push({nr,nc});
        }
    }
}

// 없어진 치즈 갯수 리턴
int Find()
{
    int removed = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] != 1) continue;
            int cnt = 0;
            if(board[i-1][j] == 2) cnt++;
            if(board[i][j+1] == 2) cnt++;
            if(board[i+1][j] == 2) cnt++;
            if(board[i][j-1] == 2) cnt++;

            if(cnt >= 2)
            {
                removed++;
                board[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] == 2) board[i][j] = 0;
        }
    }
    return removed;
}

void Print()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << board[i][j] << ' ';
        }cout<<endl;
    }cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    int answer = 0;
    while(true)
    {
        bfs();
        if(Find() == 0) break;
        answer++;
    }

    cout << answer;
}