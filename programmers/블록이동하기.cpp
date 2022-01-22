#include <string>
#include <vector>
#include <iostream>
using namespace std;

int mark[110][110][4];
vector<vector<int>> _board;
int N;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int CalDir(int r1, int c1, int r2, int c2)
{
    if(r1 == r2 && c2 > c1) return 1;
    if(c1 == c2 && r1 < r2) return 2;
    if(r1 == r2 && c1 > c2) return 3;
    else return 0;
}

void dfs(int r1, int c1, int r2, int c2, int depth)
{
    if(r1 < 0 || r1 >= N || c1 < 0 || c1 >= N || r2 < 0 || r2 >= N || c2 < 0 || c2 >= N) return;
    if(_board[r1][c1] == 1 || _board[r2][c2] == 1) return;

    cout << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;

    if((r1==N-1 && c1==N-1) || (r2==N-1 && c2==N-1))
    {
        cout << "-----------------------" << endl;
        cout << depth << endl;
        return;
    }

    int dir = CalDir(r1, c1, r2, c2);
    // 이동
    for(int i = 0; i < 4; i++)
    {
        int nr1 = r1 + dr[i];
        int nc1 = c1 + dc[i];
        int nr2 = r2 + dr[i];
        int nc2 = c2 + dc[i];

        if(nr1 < 0 || nr1 >= N || nc1 < 0 || nc1 >= N) continue;
        if(nr2 < 0 || nr2 >= N || nc2 < 0 || nc2 >= N) continue;
        if(_board[nr1][nc1] == 1 || _board[nr2][nc2] == 1) continue;
        // 기준이 되는 블록이 해당방향으로 이미 방문했으면 continue
        if(mark[nr1][nc1][dir] == 1 || (mark[nr2][nc2][(dir+2)%4] == 1)) continue;
        mark[nr1][nc1][dir] = 1; mark[nr2][nc2][(dir+2)%4] = 1;
        dfs(nr1, nc1, nr2, nc2, depth+1);
        mark[nr1][nc1][dir] = 0; mark[nr2][nc2][(dir+2)%4] = 0;
    }

    // 회전
    // r1,c1기준 오른쪽으로 뻗어있을때 (1,3)
    if(dir == 1 || dir == 3)
    {
        // r1,c1을 축으로 시계방향
        if(_board[r2+1][c2] == 0)
        {
            mark[r1][c1][2] = 1; mark[r2+1][c2-1][0] = 1;
            dfs(r1, c1, r2+1, c2-1, depth+1);
            mark[r1][c1][2] = 0; mark[r2+1][c2-1][0] = 0;
        }

        // r1,c1을 축으로 반시계 방향
        if(_board[r2-1][c2] == 0)
        {
            mark[r1][c1][0] = 1; mark[r2-1][c2-1][2] = 1;
            dfs(r1, c1, r2-1, c2-1, depth+1);
            mark[r1][c1][0] = 0; mark[r2-1][c2-1][2] = 0;
        }

        // r2,c2 축으로 시계방향
        if(_board[r1-1][c1] == 0)
        {
            mark[r1-1][c1+1][2] = 1; mark[r2][c2][0] = 1;
            dfs(r1-1, c1+1, r2, c2, depth+1);
            mark[r1-1][c1+1][2] = 0; mark[r2][c2][0] = 0;
        }

        // r2,c2 축으로 반시계 방향
        if(_board[r1+1][c1] == 0)
        {
            mark[r1+1][c1+1][0] = 1; mark[r2][c2][2] = 1;
            dfs(r1+1, c1+1, r2, c2, depth+1);
            mark[r1+1][c1+1][0] = 0; mark[r2][c2][2] = 0;
        }

    }
    else if(dir == 2 || dir == 0)
    {
        // r1,c1을 축으로 시계방향
        if(_board[r1+1][c1-1] == 0)
        {
            mark[r1][c1][3] = 1; mark[r2-1][c2-1][1] = 1;
            dfs(r1, c1, r2-1, c2-1, depth+1);
            mark[r1][c1][3] = 0; mark[r2-1][c2-1][1] = 0;
        }

        // r1,c1을 축으로 반시계
        if(_board[r1+1][c1+1] == 0)
        {
            mark[r1][c1][1] = 1; mark[r2-1][c2+1][3] = 1;
            dfs(r1, c1, r2-1, c2+1, depth+1);
            mark[r1][c1][1] = 0; mark[r2-1][c2+1][3] = 0;
        }

        // r2,c2 축으로 시계
        if(_board[r2-1][c2+1] == 0)
        {
            mark[r1+1][c1+1][3] = 1; mark[r2][c2][1] = 1;
            dfs(r1+1, c1+1, r2, c2, depth+1);
            mark[r1+1][c1+1][3] = 0; mark[r2][c2][1] = 0;
        }

        // r2,c2 축으로 반시계
        if(_board[r2-1][c2-1] == 0)
        {
            mark[r1+1][c1-1][1] = 1; mark[r2][c2][3] = 1;
            dfs(r1+1, c1-1, r2, c2, depth+1);
            mark[r1+1][c1-1][1] = 0; mark[r2][c2][3] = 0;
        }

    }
}

int solution(vector<vector<int>> board) {
    N = board.size();
    int answer = 0;
    _board = board;
    dfs(0, 0, 0, 1, 0);

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