#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int board[301][301];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};


void dfs(int r, int c, vector<vector<bool>> &visited, vector<vector<int>> &mark)
{
    visited[r][c] = true;
    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if(board[nr][nc] <= 0 || visited[nr][nc]) continue;
        // 다음 지점이 녹아 없어질 예정이라면
        if(board[nr][nc] - mark[nr][nc] <= 0)
        {
            // 해당 빙하 0으로 삭제 처리
            board[nr][nc] = 0; continue;
        }
        // 다음 지점이 녹아 없어질 예정이 아니라면 녹아야 하는만큼 녹이고 재귀 
        board[nr][nc] -= mark[nr][nc];
        dfs(nr, nc, visited, mark);

    }
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
        answer++;
        // 네 방향 0 갯수 먼저 계산한다
        vector<vector<int>> mark(N+1, vector<int>(M+1, 0));
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(board[i][j] <= 0) continue;
                int cnt = 0;
                if(board[i-1][j] <= 0) cnt++;
                if(board[i][j+1] <= 0) cnt++;
                if(board[i+1][j] <= 0) cnt++;
                if(board[i][j-1] <= 0) cnt++;
                mark[i][j] = cnt;
            }
        }

        int cnt = 0; // dfs 진행한 횟수 즉 방하 덩어리의 갯수
        vector<vector<bool>> visited(N+1, vector<bool>(M+1, false));
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                // 방문한 지점 탐색 안함
                if(visited[i][j]) continue;
                // 녹아 없어질 빙산이라면 0으로 만들고 dfs 탐색 안함
                if(board[i][j] - mark[i][j] <= 0)
                {
                    board[i][j] = 0;
                }
                // 아직 녹아 없이지지 않을 빙산이라면 dfs 탐색진행해서 빙하 덩어리 기록
                else
                {
                    board[i][j] -= mark[i][j];
                    dfs(i, j, visited, mark);
                    cnt++; // 빙하 덩어리 갯수 증가
                }
            }
        }
        // 빙하 덩어리 갯수가 0개라면 빙산이 다 녹은것
        if(cnt == 0) { cout << 0; return 0;}
        if(cnt >= 2) break;
    }
    cout << answer;
}