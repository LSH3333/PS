#include <iostream>
#include <vector>
using namespace std;

int R, C;
int dr[] = {-1, 0, 1};
int dc[] = {1, 1, 1};
int answer;

void dfs(vector<vector<char>> &board, int r, int c, bool &found)
{
    if(found) return;
    // 마지막 열 도착
    if(c == C-1)
    {
        answer++;
        found = true;
        return;
    }

    for(int i = 0; i < 3; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= R || board[nr][nc] != '.') continue;
        board[nr][nc] = 'o';
        dfs(board,  nr, nc, found);
        if(found) return;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;
    vector<vector<char>> board(R+1, vector<char>(C+1));

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }

    for(int r = 0; r < R; r++)
    {
        bool found = false;
        dfs(board, r, 0, found);
    }
    
    cout << answer;
}
