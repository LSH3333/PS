#include <iostream>
#include <vector>
using namespace std;

int N, M;
char board[51][51];
int d[51][51];
bool mark[51][51];
int answer;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int r, int c, int depth)
{
    int cnt = board[r][c] - '0';
    for(int i = 0; i < 4; i++)
    {
        int nr = r + (dr[i] * cnt);
        int nc = c + (dc[i] * cnt);
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if(board[nr][nc] == 'H') continue;

        if(mark[nr][nc])
        {
            cout << -1;
            exit(0);
        }
        if(d[nr][nc] != -1 && d[nr][nc] >= depth+1)
        {
            continue;
        }
        

        answer = max(answer, depth+1);
        mark[nr][nc] = true;
        d[nr][nc] = depth+1;

        dfs(nr, nc, depth+1);

        mark[nr][nc] = false;
    }
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            d[i][j] = -1;
        }
    }

    dfs(0, 0, 0);

    cout << answer+1;

}