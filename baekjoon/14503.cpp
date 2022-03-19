#include <iostream>
#include <vector>
using namespace std;

int a[55][55];

struct Info
{
    int r;
    int c;
    int d;
};

// 현재 좌표와 방향 기준 왼쪽 좌표와 방향 리턴 
Info Left(int r, int c, int d)
{
    switch(d)
    {
        case 0:
            return Info{r, c-1, 3};
        case 1:
            return Info{r-1, c, 0};
        case 2:
            return Info{r, c+1, 1};
        case 3:
            return Info{r+1, c, 2};
    }
    return Info{0,0,0};
}

// 현재 좌표와 방향 기준 뒤 좌표 리턴 
Info Back(int r, int c, int d)
{
    switch(d)
    {
        case 0:
            return Info{r+1, c, d};
        case 1:
            return Info{r, c-1, d};
        case 2:
            return Info{r-1, c, d};
        case 3:
            return Info{r, c+1, d};
    }
    return Info{0, 0, 0};
}


void dfs(int r, int c, int d)
{
    a[r][c] = 2;

    Info next = Left(r, c, d);
    Info back = Back(r, c, d);
    // 네 방향 모두 청소 필요한 공간 아님
    if(a[r-1][c] != 0 && a[r][c+1] != 0 && a[r+1][c] != 0 && a[r][c-1] != 0)
    {
        // 뒤가 벽임 : 종료
        if(a[back.r][back.c] == 1) return;
        // 뒤가 청소한 공간임 : 후진
        else dfs(back.r, back.c, back.d);
    }
    else
    {
        // 왼쪽에 청소할 공간이 있으면 이동
        if(a[next.r][next.c] == 0)
        {
            dfs(next.r, next.c, next.d);
        }
            // 없으면 그 방향으로 회전
        else
        {
            dfs(r, c, next.d);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, R, C, D;
    cin >> N >> M >> R >> C >> D;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }

    dfs(R, C, D);

    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(a[i][j] == 2) cnt++;
        }
    }

    cout << cnt;
}