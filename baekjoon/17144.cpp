#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int R, C, T;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int board[51][51];
vector<int> cleaner; // 공기청정기 위치

void Print()
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cout << board[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

// 확산 계산
void CalDiffusion()
{
    vector<vector<int>> temp(51, vector<int>(51, 0));
    // 미세먼지 있는 칸 별로 확산되는 미세먼지 양 계산
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(board[i][j] > 0) // 미세먼지 있는 칸
            {
                int dust = board[i][j] / 5;
                if(dust <= 0) continue; // 확산될 미세먼지 없음

                int cnt = 0; // 확산된 칸 갯수
                for(int dir = 0; dir < 4; dir++)
                {
                    int nr = i + dr[dir];
                    int nc = j + dc[dir];
                    if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                    if(board[nr][nc] == -1) continue;
                    temp[nr][nc] += dust; // 미세먼지 확산
                    cnt++;
                }

                // 확산 이후 미세먼지 감소
                board[i][j] -= (dust * cnt);
            }
        }
    }

    // 확산된 미세먼지와 칸 별로 줄어든 미세먼지 합산
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            board[i][j] += temp[i][j];
        }
    }
}

void CleanDust()
{
    // upward
    int cr = cleaner[0];
    for(int i = cr-1; i >= 1; i--) board[i][0] = board[i-1][0];
    for(int j = 0; j <= C-2; j++) board[0][j] = board[0][j+1];
    for(int i = 0; i <= cr-1; i++) board[i][C-1] = board[i+1][C-1];
    for(int j = C-1; j >= 2; j--) board[cr][j] = board[cr][j-1];
    board[cr][1] = 0;

    // downward
    cr = cleaner[1];
    for(int i = cr+1; i <= R-2; i++) board[i][0] = board[i+1][0];
    for(int j = 0; j <= C-2; j++) board[R-1][j] = board[R-1][j+1];
    for(int i = R-1; i >= cr+1; i--) board[i][C-1] = board[i-1][C-1];
    for(int j = C-1; j >= 2; j--) board[cr][j] = board[cr][j-1];
    board[cr][1] = 0;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == -1) cleaner.push_back(i);
        }
    }

    while(T--)
    {
        CalDiffusion();
        CleanDust();
    }

    int answer = 0;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(board[i][j] > 0) answer += board[i][j];
        }
    }
    cout << answer;
}