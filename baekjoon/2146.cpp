#include <iostream>
#include <queue>
using namespace std;

int N;
int board[101][101];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0 ,-1};

int bfs(int _r, int _c)
{
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<pair<int,int>,int>> q;
    q.push({{_r,_c}, 0});
    visited[_r][_c] = true;

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(visited[nr][nc]) continue;
            if(board[nr][nc] == board[_r][_c]) continue;

            // 다음 지점이 다른 대륙일때
            if(board[nr][nc] != 0 && board[nr][nc] != board[_r][_c])
            {
                return depth;
            }

            visited[nr][nc] = true;
            q.push({{nr,nc}, depth+1});
        }
    }
    return 20000;
}

bool Check(int r, int c)
{
    if(r-1 >= 0 && board[r-1][c] == 0) return true;
    if(c+1 < N && board[r][c+1] == 0) return true;
    if(r+1 < N && board[r+1][c] == 0) return true;
    if(c-1 >= 0 && board[r][c-1] == 0) return true;
    return false;
}

// 각 섬들에 번호 부여
void MarkIsland(vector<vector<bool>> &visited, int _r, int _c, int islandNum)
{
    queue<pair<int,int>> q;
    q.push({_r, _c});
    visited[_r][_c] = true;
    board[_r][_c] = islandNum;

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
            if(board[nr][nc] == 0 || visited[nr][nc]) continue;
            board[nr][nc] = islandNum;
            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
        {
            cin >> board[r][c];
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int islandNum = 1;
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
        {
            if(board[r][c] == 0 || visited[r][c]) continue;
            MarkIsland(visited, r, c, islandNum);
            islandNum++;
        }
    }
    vector<vector<bool>>().swap(visited);



    int answer = 20000;
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
        {
            if(board[r][c] == 0 || !Check(r,c)) continue;
            answer = min(answer, bfs(r, c));
        }
    }
    cout << answer;
}