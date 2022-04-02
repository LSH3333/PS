#include <iostream>
#include <vector>
using namespace std;

int R, C, ans;
char board[21][21];
bool alpMark[26];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int r, int c, int depth)
{
    ans = max(ans, depth);

    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        // 다음 지점 알파벳이 이미 쓴 알파벳이면 이동 불가
        if(alpMark[board[nr][nc]-'A']) continue;

        alpMark[board[nr][nc]-'A'] = true;
        dfs(nr, nc, depth+1);
        alpMark[board[nr][nc]-'A'] = false;
    }
}

int main()
{

    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }

    alpMark[board[0][0]-'A'] = true;
    dfs(0, 0, 1);
    cout << ans;

}
