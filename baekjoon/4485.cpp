#include <iostream>
#include <queue>
using namespace std;

int board[130][130];
int mark[130][130];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void Print(int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << mark[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

void bfs(int N)
{
    queue<pair<int,int>> q;
    q.push({0, 0});
    mark[0][0] = board[0][0];

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

            int nextVal = mark[r][c] + board[nr][nc];
            if(nextVal < mark[nr][nc])
            {
                mark[nr][nc] = nextVal;
                q.push({nr, nc});
            }
        }
    }
}

void Reset(int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            mark[i][j] = 100000;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t = 0;
    while(true)
    {
        t++;
        int N; cin >> N;
        if(N == 0) break;

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cin >> board[i][j];
            }
        }

        Reset(N);
        bfs(N);
        cout << "Problem " << t << ": " << mark[N-1][N-1] << '\n';
    }

}