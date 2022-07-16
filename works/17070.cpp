#include <iostream>
#include <vector>
using namespace std;

#define HORZ 0
#define VERT 1
#define DIAG 2

int N;
int house[20][20];
int answer;

struct Pipe
{
    int status; // 0:horz, 1:vert, 2:diag
    int r1, c1;
    int r2, c2;
};

// 가로 방향 우측 이동
bool HorzMoveRight(Pipe &pipe)
{
    if(pipe.status != HORZ) return false;
    if(pipe.c2+1 > N) return false; // 범위 체크
    if(house[pipe.r2][pipe.c2+1] == 1) return false; // 벽 체크
    pipe.c1++; pipe.c2++;
    return true;
}
// 가로 방향 대각선 이동
bool HorzMoveDiag(Pipe &pipe)
{
    if(pipe.status != HORZ) return false;
    if(pipe.r2+1 > N || pipe.c2+1 > N) return false;
    if(house[pipe.r2][pipe.c2+1] == 1 || house[pipe.r2+1][pipe.c2+1] == 1 || house[pipe.r2+1][pipe.c2] == 1) return false;
    pipe.c1++;
    pipe.r2++; pipe.c2++;
    pipe.status = DIAG;
    return true;
}
// 세로 방향 아래 이동
bool VertMoveDown(Pipe &pipe)
{
    if(pipe.status != VERT) return false;
    if(pipe.r2+1 > N) return false;
    if(house[pipe.r2+1][pipe.c2] == 1) return false;
    pipe.r1++;
    pipe.r2++;
    return true;
}
// 세로 방향 대각선 이동
bool VertMoveDiag(Pipe &pipe)
{
    if(pipe.status != VERT) return false;
    if(pipe.r2+1 > N || pipe.c2+1 > N) return false;
    if(house[pipe.r2][pipe.c2+1] == 1 || house[pipe.r2+1][pipe.c2+1] == 1 || house[pipe.r2+1][pipe.c2] == 1) return false;
    pipe.r1++;
    pipe.r2++; pipe.c2++;
    pipe.status = DIAG;
    return true;
}
// 대각선 방향 우측 이동
bool DiagMoveRight(Pipe &pipe)
{
    if(pipe.status != DIAG) return false;
    if(pipe.c2+1 > N) return false;
    if(house[pipe.r2][pipe.c2+1] == 1) return false;
    pipe.r1++; pipe.c1++;
    pipe.c2++;
    pipe.status = HORZ;
    return true;
}
// 대각선 방향 아래 이동
bool DiagMoveDown(Pipe &pipe)
{
    if(pipe.status != DIAG) return false;
    if(pipe.r2+1 > N) return false;
    if(house[pipe.r2+1][pipe.c2] == 1) return false;
    pipe.c1++; pipe.r1++;
    pipe.r2++;
    pipe.status = VERT;
    return true;
}
// 대각선 방향 대각선 이동
bool DiagMoveDiag(Pipe &pipe)
{
    if(pipe.status != DIAG) return false;
    if(pipe.c1+1 > N || pipe.r1+1 > N) return false;
    if(house[pipe.r2][pipe.c2+1] == 1 || house[pipe.r2+1][pipe.c2+1] == 1 || house[pipe.r2+1][pipe.c2] == 1) return false;
    pipe.r1++; pipe.c1++;
    pipe.r2++; pipe.c2++;
    return true;
}

void dfs(Pipe &pipe)
{
    if(pipe.r2 == N && pipe.c2 == N)
    {
        answer++;
        return;
    }
    

    Pipe save = pipe;
    if(HorzMoveRight(pipe)) { dfs(pipe); pipe = save; }
    save = pipe;
    if(HorzMoveDiag(pipe)) {  dfs(pipe); pipe = save; }
    save = pipe;
    if(VertMoveDown(pipe)) { dfs(pipe); pipe = save; }
    save = pipe;
    if(VertMoveDiag(pipe)) { dfs(pipe); pipe = save; }
    save = pipe;
    if(DiagMoveRight(pipe)) { dfs(pipe); pipe = save; }
    save = pipe;
    if(DiagMoveDown(pipe)) { dfs(pipe); pipe = save; }
    save = pipe;
    if(DiagMoveDiag(pipe)) { dfs(pipe); pipe = save; }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> house[i][j];
        }
    }

    Pipe pipe = {HORZ, 1, 1, 1, 2 };
    dfs(pipe);
    cout << answer;
}