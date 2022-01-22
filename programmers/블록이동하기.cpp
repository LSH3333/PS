#include <string>
#include <vector>
#include <iostream>
using namespace std;

int mark[110][110][4];
int _board[110][110];
int N;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int answer = 2000000000;

int CalDir(int r1, int c1, int r2, int c2)
{
    if(r1 == r2 && c2 > c1) return 1;
    if(c1 == c2 && r1 < r2) return 2;
    if(r1 == r2 && c1 > c2) return 3;
    else return 0;
}

void dfs(int r1, int c1, int r2, int c2, int depth)
{
    // 회전해서 온 시점에 예외 검사
    // 범위 벗어남
//    if(r1 <= 0 || r1 > N || c1 <= 0 || c1 > N || r2 <= 0 || r2 > N || c2 <= 0 || c2 > N) return;
//    // 회전에서 온곳이 벽임
//    if(_board[r1][c1] == 1 || _board[r2][c2] == 1) return;
//    // 이미 해당 방향으로 방문한적 있음
//    if(mark[r1][c1][CalDir(r1,c1,r2,c2)] == 1 || mark[r2][c2][CalDir(r2,c2,r1,c1)] == 1) return;

//    cout << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << " depth: " << depth << endl;
    if((r1==N && c1==N) || (r2==N && c2==N))
    {
//        cout << depth << endl;
        answer = min(answer, depth);
        return;
    }

    // 이동
    for(int i = 0; i < 4; i++)
    {
        int nr1 = r1 + dr[i];
        int nc1 = c1 + dc[i];
        int nr2 = r2 + dr[i];
        int nc2 = c2 + dc[i];

        if(nr1 <= 0 || nr1 > N || nc1 <= 0 || nc1 > N || nr2 <= 0 || nr2 > N || nc2 <= 0 || nc2 > N) continue;
        if(_board[nr1][nc1] == 1 || _board[nr2][nc2] == 1) continue;
        // r1,c1 기준 방향
        int Dir1 = CalDir(nr1, nc1, nr2, nc2);
        // r2,c2 기준 방향
        int Dir2 = CalDir(nr2, nc2, nr1, nc1);
        if(mark[nr1][nc1][Dir1] == 1 || mark[nr2][nc2][Dir2] == 1) continue;
        mark[nr1][nc1][Dir1] = 1;
        mark[nr2][nc2][Dir2] = 1;
        dfs(nr1, nc1, nr2, nc2, depth+1);
        mark[nr1][nc1][Dir1] = 0;
        mark[nr2][nc2][Dir2] = 0;
    }

    // 회전
    // r1,c1이 좌에서 우로
    if(CalDir(r1,c1,r2,c2) == 1)
    {
        // r1,c1 기준 시계
        if(r1+1 <= N && _board[r1+1][c1+1] == 0 && _board[r1+1][c1] == 0)
        {
            if(mark[r1][c1][CalDir(r1,c1,r2+1,c2-1)] == 0)
            {
                mark[r1][c1][CalDir(r1,c1,r2+1,c2-1)] = 1;
                mark[r2+1][c2-1][CalDir(r2+1,c2-1,r1,c1)] = 1;
                dfs(r1, c1, r2+1, c2-1, depth+1);
                mark[r1][c1][CalDir(r1,c1,r2+1,c2-1)] = 0;
                mark[r2+1][c2-1][CalDir(r2+1,c2-1,r1,c1)] = 0;
            }
        }
        // r1,c1 기준 반시계
        if(r1-1 > 0 && _board[r1-1][c1+1] == 0 && _board[r1-1][c1] == 0)
        {
            if(mark[r1][c1][CalDir(r1,c1,r2-1,c2-1)] == 0)
            {
                mark[r1][c1][CalDir(r1,c1,r2-1,c2-1)] = 1;
                mark[r2-1][c2-1][CalDir(r2-1,c2-1,r1,c1)] = 1;
                dfs(r1, c1, r2-1, c2-1, depth+1);
                mark[r1][c1][CalDir(r1,c1,r2-1,c2-1)] = 0;
                mark[r2-1][c2-1][CalDir(r2-1,c2-1,r1,c1)] = 0;
            }
        }
        // r2,c2 기준 시계
        if(r2-1 > 0 && _board[r2-1][c2] == 0 && _board[r2-1][c2-1] == 0)
        {
            if(mark[r1-1][c1+1][CalDir(r1-1,c1+1,r2,c2)] == 0)
            {
                mark[r1-1][c1+1][CalDir(r1-1,c1+1,r2,c2)] = 1;
                mark[r2][c2][CalDir(r2,c2,r1-1,c1+1)] = 1;
                dfs(r1-1, c1+1, r2, c2, depth+1);
                mark[r1-1][c1+1][CalDir(r1-1,c1+1,r2,c2)] = 0;
                mark[r2][c2][CalDir(r2,c2,r1-1,c1+1)] = 0;
            }
        }
        // r2,c2 기준 반시계
        if(r1+1 <= N && _board[r2+1][c2] == 0 && _board[r2+1][c2-1] == 0)
        {
            if(mark[r1+1][c1+1][CalDir(r1+1,c1+1,r2,c2)] == 0)
            {
                mark[r1+1][c1+1][CalDir(r1+1,c1+1,r2,c2)] = 1;
                mark[r2][c2][CalDir(r2,c2,r1+1,c1+1)] = 1;
                dfs(r1+1, c1+1, r2, c2, depth+1);
                mark[r1+1][c1+1][CalDir(r1+1,c1+1,r2,c2)] = 0;
                mark[r2][c2][CalDir(r2,c2,r1+1,c1+1)] = 0;
            }
        }
    }
        // r1,c1이 우에서 좌로
    else if(CalDir(r1,c1,r2,c2) == 3)
    {
        // r1,c1 기준 시계
        if(r1-1 > 0 && _board[r1-1][c1] == 0 && _board[r1-1][c1-1] == 0)
        {
            if(mark[r1][c1][CalDir(r1,c1,r2-1,c2+1)] == 0)
            {
                mark[r1][c1][CalDir(r1,c1,r2-1,c2+1)] = 1;
                mark[r2-1][c2+1][CalDir(r2-1,c2+1,r1,c1)] = 1;
                dfs(r1, c1, r2-1, c2+1, depth+1);
                mark[r1][c1][CalDir(r1,c1,r2-1,c2+1)] = 0;
                mark[r2-1][c2+1][CalDir(r2-1,c2+1,r1,c1)] = 0;
            }
        }
        // r1,c1 기준 반시계
        if(r1+1 <= N && _board[r1+1][c1] == 0 && _board[r1+1][c1-1] == 0)
        {
            if(mark[r1][c1][CalDir(r1,c1,r2+1,c2+1)] == 0)
            {
                mark[r1][c1][CalDir(r1,c1,r2+1,c2+1)] = 1;
                mark[r2+1][c2+1][CalDir(r2+1,c2+1,r1,c1)] = 1;
                dfs(r1, c1, r2+1, c2+1, depth+1);
                mark[r1][c1][CalDir(r1,c1,r2+1,c2+1)] = 0;
                mark[r2+1][c2+1][CalDir(r2+1,c2+1,r1,c1)] = 0;
            }
        }
        // r2,c2 기준 시계
        if(r2+1 <= N && _board[r2+1][c2] == 0 && _board[r2+1][c2+1] == 0)
        {
            if(mark[r1+1][c1-1][CalDir(r1+1,c1-1,r2,c2)] == 0)
            {
                mark[r1+1][c1-1][CalDir(r1+1,c1-1,r2,c2)] = 1;
                mark[r2][c2][CalDir(r2,c2,r1+1,c1-1)] = 1;
                dfs(r1+1, c1-1, r2, c2, depth+1);
                mark[r1+1][c1-1][CalDir(r1+1,c1-1,r2,c2)] = 0;
                mark[r2][c2][CalDir(r2,c2,r1+1,c1-1)] = 0;
            }
        }
        // r2,c2 기준 반시계
        if(r2-1 > 0 && _board[r2-1][c2] == 0 && _board[r2-1][c2+1] == 0)
        {
            if(mark[r1-1][c1-1][CalDir(r1-1,c1-1,r2,c2)] == 0)
            {
                mark[r1-1][c1-1][CalDir(r1-1,c1-1,r2,c2)] = 1;
                mark[r2][c2][CalDir(r2,c2,r1-1,c1-1)] = 1;
                dfs(r1-1, c1-1, r2, c2, depth+1);
                mark[r1-1][c1-1][CalDir(r1-1,c1-1,r2,c2)] = 0;
                mark[r2][c2][CalDir(r2,c2,r1-1,c1-1)] = 0;
            }
        }
    }
        // r1,c1이 위에서 아래로
    else if(CalDir(r1,c1,r2,c2) == 2)
    {
        // r1,c1 기준 시계
        if(c1-1 > 0 && _board[r1][c1-1] == 0 && _board[r1+1][c1-1] == 0)
        {
            if(mark[r1][c1][CalDir(r1,c1,r2-1,c2-1)] == 0)
            {
                mark[r1][c1][CalDir(r1,c1,r2-1,c2-1)] = 1;
                mark[r2-1][c2-1][CalDir(r2-1,c2-1,r1,c1)] = 1;
                dfs(r1, c1, r2-1, c2-1, depth+1);
                mark[r1][c1][CalDir(r1,c1,r2-1,c2-1)] = 0;
                mark[r2-1][c2-1][CalDir(r2-1,c2-1,r1,c1)] = 0;
            }
        }
        // r1,c1 기준 반시계
        if(c1+1 <= N && _board[r1][c1+1] == 0 && _board[r1+1][c1+1] == 0)
        {
            if(mark[r1][c1][CalDir(r1,c1,r2-1,c2+1)] == 0)
            {
                mark[r1][c1][CalDir(r1,c1,r2-1,c2+1)] = 1;
                mark[r2-1][c2+1][CalDir(r2-1,c2+1,r1,c1)] = 1;
                dfs(r1, c1, r2-1, c2+1, depth+1);
                mark[r1][c1][CalDir(r1,c1,r2-1,c2+1)] = 0;
                mark[r2-1][c2+1][CalDir(r2-1,c2+1,r1,c1)] = 10;
            }
        }
        // r2,c2 기준 시계
        if(c2+1 <= N && _board[r2][c2+1] == 0 && _board[r2-1][c2+1] == 0)
        {
            if(mark[r1+1][c1+1][CalDir(r1+1,c1+1,r2,c2)] == 0)
            {
                mark[r1+1][c1+1][CalDir(r1+1,c1+1,r2,c2)] = 1;
                mark[r2][c2][CalDir(r2,c2,r1+1,c1+1)] = 1;
                dfs(r1+1, c1+1, r2, c2, depth+1);
                mark[r1+1][c1+1][CalDir(r1+1,c1+1,r2,c2)] = 0;
                mark[r2][c2][CalDir(r2,c2,r1+1,c1+1)] = 0;
            }
        }
        // r2,c2 기준 반시계
        if(c2-1 > 0 && _board[r2][c2-1] == 0 && _board[r2-1][c2-1] == 0)
        {
            if(mark[r1+1][c1-1][CalDir(r1+1,c1-1,r2,c2)] == 0)
            {
                mark[r1+1][c1-1][CalDir(r1+1,c1-1,r2,c2)] = 1;
                mark[r2][c2][CalDir(r2,c2,r1+1,c1-1)] = 1;
                dfs(r1+1, c1-1, r2, c2, depth+1);
                mark[r1+1][c1-1][CalDir(r1+1,c1-1,r2,c2)] = 0;
                mark[r2][c2][CalDir(r2,c2,r1+1,c1-1)] = 0;
            }
        }
    }
        // r1,c1이 아래서 위로
    else
    {
        // r1,c1 기준 시계
        if(c1+1 <= N && _board[r1][c1+1] == 0 && _board[r1-1][c1+1] == 0)
        {
            if(mark[r1][c1][CalDir(r1,c1,r2+1,c2+1)] == 0)
            {
                mark[r1][c1][CalDir(r1,c1,r2+1,c2+1)] = 1;
                mark[r2+1][c2+1][CalDir(r2+1,c2+1,r1,c1)] = 1;
                dfs(r1, c1, r2+1, c2+1, depth+1);
                mark[r1][c1][CalDir(r1,c1,r2+1,c2+1)] = 0;
                mark[r2+1][c2+1][CalDir(r2+1,c2+1,r1,c1)] = 0;
            }
        }
        // r1,c1 기준 반시계
        if(c1-1 > 0 && _board[r1][c1-1] == 0 && _board[r1-1][c1-1] == 0)
        {
            if(mark[r1][c1][CalDir(r1,c1,r2+1,c2-1)] == 0)
            {
                mark[r1][c1][CalDir(r1,c1,r2+1,c2-1)] = 1;
                mark[r2+1][c2-1][CalDir(r2+1,c2-1,r1,c1)] = 1;
                dfs(r1, c1, r2+1, c2-1, depth+1);
                mark[r1][c1][CalDir(r1,c1,r2+1,c2-1)] = 0;
                mark[r2+1][c2-1][CalDir(r2+1,c2-1,r1,c1)] = 0;
            }
        }
        // r2,c2 기준 시계
        if(c2-1 > 0 && _board[r2][c2-1] && _board[r2+1][c2-1] == 0)
        {
            if(mark[r1-1][c1-1][CalDir(r1-1,c1-1,r2,c2)] == 0)
            {
                mark[r1-1][c1-1][CalDir(r1-1,c1-1,r2,c2)] = 1;
                mark[r2][c2][CalDir(r2,c2,r1-1,c1-1)] = 1;
                dfs(r1-1, c1-1, r2, c2, depth+1);
                mark[r1-1][c1-1][CalDir(r1-1,c1-1,r2,c2)] = 0;
                mark[r2][c2][CalDir(r2,c2,r1-1,c1-1)] = 0;
            }
        }
        // r2,c2 기준 반시계
        if(c2+1 <= N && _board[r2][c2+1] == 0 && _board[r2+1][c2+1] == 0)
        {
            if(mark[r1-1][c1+1][CalDir(r1-1,c1+1,r2,c2)] == 0)
            {
                mark[r1-1][c1+1][CalDir(r1-1,c1+1,r2,c2)] = 1;
                mark[r2][c2][CalDir(r2,c2,r1-1,c1+1)] = 1;
                dfs(r1-1, c1+1, r2, c2, depth+1);
                mark[r1-1][c1+1][CalDir(r1-1,c1+1,r2,c2)] = 0;
                mark[r2][c2][CalDir(r2,c2,r1-1,c1+1)] = 0;
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    N = board.size();

    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            _board[i+1][j+1] = board[i][j];
        }
    }
    mark[1][1][1] = 1;
    mark[1][2][3] = 1;

    dfs(1, 1, 1, 2, 0);
//    cout << answer;
    return answer;
}

int main()
{
    vector<vector<int>> board =
            {
                    {0,0,0,1,1},
                    {0,0,0,1,0},
                    {0,1,0,1,1},
                    {1,1,0,0,1},
                    {0,0,0,0,0}
            };
    solution(board);
}