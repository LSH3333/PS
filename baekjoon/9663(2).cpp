#include <iostream>
using namespace std;

int n;
int ans = 0;
int map[15][15];

int dr[3] = {-1, -1, -1};
int dc[3] = {-1, 0, 1};

// 북서, 북, 북동 방향 경로에 퀸있는지 탐색 
bool Check(int r, int c)
{
    for(int i = 0; i < 3; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        // 체스판 범위 벗어나지 않을때까지 퀸이 있나 체크
        while(nr >= 0 && nc >= 0 && nc < n)
        {
            // 퀸이 있으므로 해당하는 자리에는 퀸을 놓을수 없음
            if(map[nr][nc] == 1) return false;
            nr += dr[i];
            nc += dc[i];
        }
    }
    return true;
}


void NQueen(int depth)
{
    if(depth == n)
    {

        ans++;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        // 퀸을 놓을수 있는곳이라면
        if(Check(depth, i))
        {
            map[depth][i] = 1;

            NQueen(depth+1);

            map[depth][i]= 0;
        }
    }

}

int main()
{
    cin >> n;

    NQueen(0);

    cout << ans;
}