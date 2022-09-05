#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int R, C;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<pair<int,int>> &fires, pair<int,int> &jiHoon, vector<vector<char>> &board)
{
    vector<vector<bool>> visited(R+1, vector<bool>(C+1, false));
    visited[jiHoon.first][jiHoon.second] = true;

    queue<pair<pair<int,int>,int>> q;
    q.push({{jiHoon.first, jiHoon.second}, 0});
    for(auto x : fires) q.push({{x.first, x.second}, 0});

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        if (board[r][c] == 'J')
        {
            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nr >= R || nc < 0 || nc >= C) // 탈출
                {
                    return depth+1;
                }
                if(board[nr][nc] == '#' || board[nr][nc] == 'F' || visited[nr][nc]) continue;
                q.push({{nr,nc}, depth+1});
                board[nr][nc] = 'J';
                visited[nr][nc] = true;
            }
            board[r][c] = '.';
        }
        else if(board[r][c] == 'F')
        {
            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if(board[nr][nc] == '#' || board[nr][nc] == 'F') continue;
                q.push({{nr,nc}, depth+1});
                board[nr][nc] = 'F';
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;
    vector<vector<char>> board(R+1, vector<char>(C+1));
    vector<pair<int,int>> fires;
    pair<int,int> jiHoon;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'J') { jiHoon = {i,j}; }
            else if(board[i][j] == 'F') fires.push_back({i, j});
        }
    }

    int res = bfs(fires, jiHoon, board);
    if(res == -1) cout << "IMPOSSIBLE";
    else cout << res;
}

