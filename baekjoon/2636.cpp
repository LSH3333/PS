#include <iostream>
#include <queue>
using namespace std;

int R, C;
int board[110][110];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int cheese = 0; // 치즈칸 갯수
int lastCheese = 0;

// 구멍이 아닌 치즈가 아닌곳 판단
void FindOutside()
{
    vector<vector<bool>> mark(110, vector<bool>(110, false));
    queue<pair<int,int>> q;
    mark[0][0] = true;
    board[0][0] = 2;
    q.push({0,0});

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(mark[nr][nc] || board[nr][nc] == 1) continue;
            mark[nr][nc] = true;
            board[nr][nc] = 2; // 외부 공간 2로 표시
            q.push({nr,nc});
        }
    }
}

void Melt()
{
    lastCheese = cheese;
    FindOutside();

    for(int i = 1; i < R-1; i++)
    {
        for(int j = 1; j < C-1; j++)
        {
            if(board[i][j] != 1) continue;
            if(board[i-1][j] == 2 || board[i][j-1] == 2 || board[i+1][j] == 2 || board[i][j+1] == 2)
            {
                board[i][j] = 3;
                cheese--;
            }
        }
    }


    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(board[i][j] == 3)
            {
                board[i][j] = 2;
            }
        }
    }

}



int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 1) cheese++;
        }
    }

    int sec = 0;
    while(cheese > 0)
    {
        sec++;
        Melt();
    }

    cout << sec << endl;
    cout << lastCheese;
}