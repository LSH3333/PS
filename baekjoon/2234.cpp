#include <iostream>
#include <queue>
using namespace std;

int R, C;
bool board[55][55][4];

// 서 북 동 남
int dr[]  = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};
int answer1, answer2, answer3;

void CalRoom(int _r, int _c, int val)
{
    int idx = 0;
    while(val > 0)
    {
        int left = val % 2;
        board[_r][_c][idx++] = left; // true시 벽
        val /= 2;
    }
}

int bfs(vector<vector<bool>> &visited, int _r, int _c)
{
    visited[_r][_c] = true;
    queue<pair<int,int>> q;
    q.push({_r,_c});
    int ret = 0;

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        ret++;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(board[r][c][i]) continue; // 해당 방향에 벽
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr,nc});
        }
    }
    return ret;
}

void CalBoard1()
{
    vector<vector<bool>> visited(55, vector<bool>(55, false));
    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            if(visited[r][c]) continue;
            answer2 = max(answer2, bfs(visited, r, c));
            answer1++;
        }
    }
}

void CalBoard2()
{
    // 벽 제거
    for(int _r = 0; _r < R; _r++)
    {
        for(int _c = 0; _c < C; _c++)
        {
            for(int k = 0; k < 4; k++)
            {
                int _nr = _r + dr[k];
                int _nc = _c + dc[k];
                if(_nr < 0 || _nr >= R || _nc < 0 || _nc >= C) continue;

                if(board[_r][_c][k])
                {
                    board[_r][_c][k] = false; // 벽 있다면 벽 제거

                    vector<vector<bool>> visited(55, vector<bool>(55, false));
                    for(int r = 0; r < R; r++)
                    {
                        for(int c = 0; c < C; c++)
                        {
                            if(visited[r][c]) continue;
                            answer3 = max(answer3, bfs(visited, r, c));
                        }
                    }

                    board[_r][_c][k] = true; // 벽 복구
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> C >> R;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            int val; cin >> val;
            CalRoom(i, j, val);
        }
    }

    CalBoard1();
    CalBoard2();

    cout << answer1 << '\n' << answer2 << '\n' << answer3;
}